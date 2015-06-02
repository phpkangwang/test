// MySock.cpp : ʵ���ļ�
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


// CMySock ��Ա����


void CMySock::OnReceive(int nErrorCode)
{
	//�������յ������ݵ�ͷ
	char buf[BUF_SIZE];	
	CString sIp;
	UINT nPort;
	//���յ����ֽ���
	int nBytes = ReceiveFrom(buf,BUF_SIZE,sIp,nPort);
	//�յ�����Ϣ�ֽ�������3��������
	if(nBytes <3)
	{
		//����
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
		//�Է�Ҫ�����ļ������߶Է��Ƿ����
		if(MessageBox(p->m_hWnd,_T("�Է��������ļ����Ƿ����"),_T("��ʾ"),MB_YESNO) == IDYES)
		{
			if(m_fp != NULL)
			{
				//���ڽ����ļ���֪ͨ�Է�������
				SendTo("2220",5,nPort,sIp,0);
			}
			else
			{
				//û�����ڽ����ļ������Խ���
				//�����ļ�����Ϣ(�ļ�������С)
				CStringA FileInfo = buf+3;
				int nIndex = FileInfo.Find('#');
				CString FileName = CA2W( FileInfo.Left(nIndex) );
				CStringA size = FileInfo.Mid(nIndex+1);
				long FileSize = atoi(size);
				CFileDialog fd(FALSE,NULL,FileName);
				//���ý�����
				p->m_progress.SetRange32(0,FileSize);
				p->m_progress.SetPos(0);
				if(fd.DoModal() == IDCANCEL)
				{
					//ȡ���˱��棬����Ϊ�������ļ�
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
			//�ж϶Է��Ƿ�����ļ�����
			char c = buf[3];
			if( c == '0')
			{
				//�����գ��ر��ļ�ָ��
				if(m_fp != NULL )
				{
					fclose(m_fp);
					m_fp = NULL;
				}
			}
			else
			{
				m_mutex.Lock();
				//����,��ʼ���ļ��ж����ݣ�����
				char send[BUF_SIZE];
				int nRet = fread(send+3,1,FILE_BLOCK_SIZE,m_fp);
				//�ļ�����������ϣ���ͷ�ļ���֪ͨ�Է��ļ��������
				if(nRet <FILE_BLOCK_SIZE)
				{
					memcpy(send,"444",3);
					SendTo(send,nRet+3,nPort,sIp);
					int nPos = p->m_progress.GetPos();
					p->m_progress.SetPos(nPos + nRet);
					fclose(m_fp);
					m_fp = NULL;
					p->m_progress.SetPos(0);
					MessageBox(p->m_hWnd,_T("�ɹ��������"),_T("��ʾ"),MB_OK);
					
				}
				//��ͷ�ļ���֪ͨ�Է����걾�λ�Ҫ���������ļ�
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
		//�յ��ļ��������ļ�Ҫ����,��֪ͨ�Է����Լ�������
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
		//�ļ�������ϣ�д���ر��ļ�
		fwrite(buf+3,1,nBytes-3,m_fp);
		fclose(m_fp);
		m_fp = NULL;
		int nPos = p->m_progress.GetPos();
		p->m_progress.SetPos(nPos + nBytes);

		p->m_progress.SetPos(0);
		MessageBox(p->m_hWnd,_T("�ɹ������ļ�"),_T("��ʾ"),MB_OK);

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
			MessageBox(p->m_hWnd,_T("�Է�ȡ������"),_T("��ʾ"),MB_OK);
			m_mutex.Unlock();
		}
	}
	else
	{
		//����ͷ����Ϣ����
	}

	CAsyncSocket::OnReceive(nErrorCode);
}


void CMySock::OnSend(int nErrorCode)
{
	

	CAsyncSocket::OnSend(nErrorCode);
}
