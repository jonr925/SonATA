#!/bin/sh

# sonata-cron-end-obs-session.sh

# terminate a SonATA observing session

# send commands to SSE to stop observing
${HOME}/sonata_install/bin/sonata-seeker-command-cron-wrapper.sh source ${HOME}/OpenSonATA/scripts/sonata-stop-obs.tcl

# wait for system to wrap up
sleep 30

#shutdown sse
${HOME}/sonata_install/bin/sonata-shutdown-cron-wrapper.sh
