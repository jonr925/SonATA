#set args -s -B 200 -P 10 -S 200 -D .15 -q -h gecko
#set args -s -B 200 -P 1 -S 256 -D .5 -q -h gecko.site
#set args -H cataclysm -f 10 -z ../../filters/LS256c10f25o -p x -Q dx1000
set args -H sirocco -f 10 -z ../../filters/LS256c10f25o70d.flt -I 227.1.1.1 -i 51000 -Q dx1000 -p x -F 32
set disassembly-flavor intel
