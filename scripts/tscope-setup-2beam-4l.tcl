# 22 beams, antenna 4L
# tscope-setup-2beam-4l.tcl

act set targetbeam1 160
act set targetbeam2 160
act set targetbeam3 160
act set targetprimary 160
act set type target
act set candarch confirmed
act set multitargetnulls off

sched set beginfreq 8421.2 
sched set endfreq 8426.2
sched set dxtune range
sched set rftune auto
sched set target user
sched set multitarget on
sched set beam1 on
sched set beam2 off
sched set beam3 on
sched set tasks prepants,bfreset,bfautoatten,bfinit,caldelay


dx set length 48
dx set datareqsubchan 384
dx set baseinitaccum 5
dx set basewarn off
dx set baseerror off

db set name sonatadb
db set usedb on

tscope set antlistsource param
tscope set antsprimary  4l
tscope set antsxpol 4l
tscope set antsypol 4l
# both tunings must be the same
tscope set tuningc 8425.0
tscope set tuningd 8425.0
 tscope assign beamxc1 4l
 tscope assign beamyc1 4l
 tscope assign beamxd1 4l
 tscope assign beamyd1 4l
 tscope assign beamxd2 4l
 tscope assign beamyd2 4l

