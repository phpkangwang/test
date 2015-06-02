// MySock.cpp : 实现文件
//

#include "stdafx.h"
#include "SockFile.h"
#include "MySock.h"
#include "SockFileDlg.h"

// CMySock

CMySock::CMySock(CWnd* pWnd)
{
	m_pWnd = pWnd;
	m_fp = NULL;
	m_nCount = 0;
}

CMySock::~CMySock()
{
}


// CMySock 成员函数


void CMySock::OnReceive(int nErrorCode)
{
	//解析接收到的数据的头
	char buf[BUF_SIZE];	
	CString sIp;
	UINT nPort;
	//接收到的字节数
	int nBytes = ReceiveFrom(buf,BUF_SIZE,sIp,nPort);
	//收到的信息字节数少于3，有问题
	if(nBytes <3)
	{
		//处理
		return;
	}
	char header[4];
	memset(header,0,4);
	memcpy(header,buf,3);

	CSockFileDlg* p = (CSockFileDlg*)m_pWnd;
	CStringA sa = header;
	if(sa == "000")
	{
		sa = buf+3;
		CString ss = CA2W(sa);
		SYSTEMTIME time;
		::GetLocalTime(&time);
		CString stime;
		stime.Format(_T("%d:%d:%d"),time.wHour,time.wMinute,time.wSecond);
		p->m_RecordList.AddString(stime);
		p->m_RecordList.AddString(ss);
	}
	else if(sa == "111")
	{
		//对方要发送文件，告诉对方是否接收
		if(MessageBox(p->m_hWnd,_T("对方请求发送文件，是否接收"),_T("提示"),MB_YESNO) == IDYES)
		{
			if(m_fp != NULL)
			{
				//正在接收文件，通知对方不接受
				SendTo("2220",5,nPort,sIp,0);
			}
			else
			{
				//没有正在接收文件，可以接收
				//解析文件的信息(文件名、大小)
				CStringA FileInfo = buf+3;
				int nIndex = FileInfo.Find('#');
				CString FileName = CA2W( FileInfo.Left(nIndex) );
				CStringA size = FileInfo.Mid(nIndex+1);
				long FileSize = atoi(size);
				CFileDialog fd(FALSE,NULL,FileName);
				//设置进度条
				p->m_progress.SetRange32(0,FileSize);
				p->m_progress.SetPos(0);
				if(fd.DoModal() == IDCANCEL)
				{
					//取消了保存，即认为不接收文件
					SendTo("2220",5,nPort,sIp,0);
				}
				else
				{
					CString saveName = fd.GetFileName();
					m_fp = fopen(CW2A(saveName),"wb");
					SendTo("2221",5,nPort,sIp,0);
				}
			}
		}
		else
		{
			SendTo("2220",5,nPort,sIp,0);
		}

	}
	else if(sa == "222")
	{
		if(m_fp != NULL)
		{
			//判断对方是否接收文件传输
			char c = buf[3];
			if( c == '0')
			{
				//不接收，关闭文件指针
				if(m_fp != NULL )
				{
					fclose(m_fp);
					m_fp = NULL;
				}
			}
			else
			{
				m_mutex.Lock();
				//接收,开始从文件中读数据，发送
				char send[BUF_SIZE];
				int nRet = fread(send+3,1,FILE_BLOCK_SIZE,m_fp);
				//文件即将传送完毕，加头文件，通知对方文件传输完毕
				if(nRet <FILE_BLOCK_SIZE)
				{
					memcpy(send,"444",3);
					SendTo(send,nRet+3,nPort,sIp);
					int nPos = p->m_progress.GetPos();
					p->m_progress.SetPos(nPos + nRet);
					fclose(m_fp);
					m_fp = NULL;
					p->m_progress.SetPos(0);
					MessageBox(p->m_hWnd,_T("成功发送完毕"),_T("提示"),MB_OK);
					
				}
				//加头文件，通知对方传完本次还要继续传输文件
				else
				{
					memcpy(send,"333",3);
					SendTo(send,nRet+3,nPort,sIp);

					int nPos = p->m_progress.GetPos();
					p->m_progress.SetPos(nPos + nRet);
				}
				
				m_mutex.Unlock();
			}
		}
	}
	else if(sa == "333")
	{
		m_mutex.Lock();
		//收到文件，还有文件要接收,并通知对方可以继续传输
		fwrite(buf+3,1,nBytes-3,m_fp);		
		SendTo("2221",5,nPort,sIp);
		//
		int nPos = p->m_progress.GetPos();
		p->m_progress.SetPos(nPos + nBytes);
		m_mutex.Unlock();
	}
	else if(sa == "444")
	{
		m_mutex.Lock();
		//文件传输完毕，写入后关闭文件
		fwrite(buf+3,1,nBytes-3,m_fp);
		fclose(m_fp);
		m_fp = NULL;
		int nPos = p->m_progress.GetPos();
		p->m_progress.SetPos(nPos + nBytes);

		p->m_progress.SetPos(0);
		MessageBox(p->m_hWnd,_T("成功接收文件"),_T("提示"),MB_OK);

		m_mutex.Unlock();
	}
	else if( sa == "555")
	{
		if(m_fp != NULL)
		{
			m_mutex.Lock();
			fclose(m_fp);
			m_fp = NULL;
			p->m_progress.SetPos(0);
			MessageBox(p->m_hWnd,_T("对方取消发送"),_T("提示"),MB_OK);
			m_mutex.Unlock();
		}
	}
	else
	{
		//解析头部信息出错
	}

	CAsyncSocket::OnReceive(nErrorCode);
}


void CMySock::OnSend(int nErrorCode)
{
	

	CAsyncSocket::OnSend(nErrorCode);
}
