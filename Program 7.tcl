#Create a simulator object
set ns [new Simulator]
#Define different colors for data flows (for NAM)
$ns color 1 Blue
$ns color 2 Red
#Open the NAM trace file
set nf [open 7.nam w]
$ns namtrace-all $nf
set tf [open 7.tr w]
$ns trace-all $tf
#Create five nodes
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
#Create links between the nodes
$ns duplex-link $n0 $n4 1Mb 10ms DropTail
$ns duplex-link $n1 $n4 1Mb 10ms DropTail
$ns duplex-link $n4 $n3 1Mb 10ms DropTail
$ns duplex-link $n4 $n2 1Mb 10ms DropTail
#Setup a TCP connection

set tcp [new Agent/TCP]
$ns attach-agent $n0 $tcp
set sink [new Agent/TCPSink]
$ns attach-agent $n3 $sink
$ns connect $tcp $sink
set ftp [new
Application/FTP]
$ftp attach-agent $tcp
#Setup a UDP connection
set udp [new Agent/UDP]
$ns attach-agent $n1 $udp
set null [new Agent/Null]
$ns attach-agent $n2 $null
$ns connect $udp $null
#Setup a CBR over UDP
set cbr [new
Application/Traffic/CBR]
$cbr attach-agent $udp
$cbr set packet_size_ 500
#Schedule events for the CBR and FTP
agents $ns at 0.0 "$cbr start"
$ns at 0.0 "$ftp start"
$ns at 20.0 "$ftp stop"
$ns at 20.0 "$cbr stop"
#Define a 'finish' procedure

proc finish {} {
global ns nf tf
$ns flush-trace
close $nf
close $tf
exec nam 7.nam &
exit 0
}
$ns at 10.0 "finish"
#Run the simulation
$ns run

======================
7.awk:-
BEGIN{
udp=0;
tcp=0;
}
{
if($1 == "r" && $5 == "cbr")
{
udp++;
}
else if($1 == "r" && $5 == "tcp")
{
tcp++;
}
}
END{
printf("Number of packets sent by TCP = %d\n", tcp);
printf("Number of packets sent by UDP=%d\n",udp);
