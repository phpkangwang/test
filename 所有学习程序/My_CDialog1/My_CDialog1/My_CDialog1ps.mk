
My_CDialog1ps.dll: dlldata.obj My_CDialog1_p.obj My_CDialog1_i.obj
	link /dll /out:My_CDialog1ps.dll /def:My_CDialog1ps.def /entry:DllMain dlldata.obj My_CDialog1_p.obj My_CDialog1_i.obj \
		kernel32.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \
.c.obj:
	cl /c /Ox /DREGISTER_PROXY_DLL \
		$<

clean:
	@del My_CDialog1ps.dll
	@del My_CDialog1ps.lib
	@del My_CDialog1ps.exp
	@del dlldata.obj
	@del My_CDialog1_p.obj
	@del My_CDialog1_i.obj
