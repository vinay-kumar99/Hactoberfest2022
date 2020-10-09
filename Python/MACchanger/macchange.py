#!/usr/bin/python

#this program is used to change mac address of a machine which helps you to use for using different NIC cards..do not use for illegal purpose 
#CAUTION:Scan for the IPs which you have permissions to, otherwise it is an act of cybercrime..
#RECCOMENDATION: Use linux terminals to execute the codes for better result
#command: python3 macchanger.py

import subprocess
#it allows you to execute system commands and checkout the outout they give inorder to see the macaddress
from termcolor import colored

def change_mac_address(interface,mac):

	subprocess.call(["ifconfig",interface,"down"])
	subprocess.call(["ifconfig",interface,"hw","ether",mac])
	subprocess.call(["ifconfig",interface,"up"])



def main():
	interface = str(input(colored("[*] Enter Interface To Change Mac Address on: ",'yellow')))
	#insert interface i.e. eth0, others
	new_mac_address = input(colored("[*] Enter Mac Address to change to: ",'blue'))

	before_change = subprocess.check_output(["ifconfig",interface])
	change_mac_address(interface,new_mac_address)
	after_change = subprocess.check_output(["ifconfig",interface])

	if before_change == after_change:
		print(colored("[!!] Failed to change MAC address to: " + new_mac_address,'red'))
	else:
		print(colored("[+] MAC address change to: " + new_mac_address + " on interface " + interface,'green'))

main()
