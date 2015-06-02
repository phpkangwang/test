rem 用之前，请先拷贝到vc工程下
rem 清除vc6垃圾文件
@echo on
@echo "清除vc6垃圾文件"
del *.aps
del *.opt
del *.ncb
del *.plg
del *.sdf
rd /Q /S debug
rd /Q /S ipch