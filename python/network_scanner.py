#!/usr/bin/python3

# Simple network scanner program in python3 with scapy (library)
# Need root access to run this program (non-windows)

# usage: just type the ip in scan() as per format and run program (`python3 network_scanner.py`)
#        need to `pip install scapy` beforehand!


import scapy.all as scapy

def scan(ip):

	# Creating ARP Packet 
	arp_request = scapy.ARP(pdst=ip)
	broadcast = scapy.Ether(dst='ff:ff:ff:ff:ff:ff')
	arp_request_broadcast = broadcast/arp_request

	# Sending & Receving ARP request
	answered_list = scapy.srp(arp_request_broadcast, timeout=1, verbose=False)[0]
	# answered_list, unanswered_list = scapy.srp(arp_request_broadcast, timeout=1)

	print("IP\t\t\tMAC ADDRESS\n-----------------------------------------")

	# Parsing data
	for element in answered_list:
		print(element[1].psrc + '\t\t' + element[1].hwsrc)


# enter ip to scan here (format: XXX.XXX.XXX.1/24)
scan('192.168.150.1/24')


