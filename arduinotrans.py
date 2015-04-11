import sys
import serial
import time
import os
import os.path
import random

#ser = serial.Serial(2, 9600)

#fname='C:\\Users\\Ziran\\AppData\\Roaming\\HexChat\\logs\\lastsession.txt'
fname='C:\\Users\\Ziran\\AppData\\Roaming\\HexChat\\logs\\lastsession.log'
#fname='/Volumes/BOOTCAMP/Users/Ziran/Desktop/lastsession.txt'
old=0
modeselect=1
one=1
while(1==one):
	while (1==modeselect):
		#print 'swag'
		#print os.path.isfile('/Volumes/BOOTCAMP/Users/')
		try:
			fhand=open(fname,'r')
			
		except:
			print 'Try again:',fname
			exit()
		j=1
		for line in fhand:
			if (j>old):
				if line.startswith('<'):
					linenum=line.find(">")
					function=line[linenum+2:]
					if function.startswith('!write '):
						output=line[linenum+9:]
						print '~'
						print '$'
						#ser.write('~')
						#ser.write('$')
						for char in output:
							print char
							#ser.write(char)
							#time.sleep(1)
					elif function.startswith('!move '):
						output=line[linenum+8:]
						print '~'
						print '@'
						#ser.write("~")
						#ser.write('@')
						for char in output:
							print char
							#ser.write(char)
							#time.sleep(1)
					elif function.startswith('!erase '):
						output=line[linenum+9:]
						print '~'
						print '#'
						#ser.write('~')
						#ser.write('#')
						for char in output:
							print char
							#ser.write(char)
							#time.sleep(1)
					elif line.startswith('<beatrng>'):
						if function.startswith('!switchset 2'):
							print '~'
							print '!'
							#ser.write('~')
							#ser.write('!')
							modeselect=2
				old=old+1
			j=j+1
		fhand.close()
	hangmanStarted = 0
	hangmanCounter = 0
	wordlist = 'C:\\Users\\Ziran\\Anaconda\\wordlist.txt'
	while (2==modeselect):
		if (hangmanStarted==0):
			lineChosen = random.randrange(1,2000)
			fp = open(wordlist)
			for i, line in enumerate(fp):
				if i == lineChosen:
					#print i
					if (len(line)>6):
						wordChosen=line
						badLetters=""
						usedLetters=""
						hangmanStarted=1
						print wordChosen
						break
	    			#else:
	    				#lineChosen=lineChosen+1
			#tell arduino hangman started aka draw the layout of the shit and erase the stuff before
		try:
			fhand=open(fname,'r')
		except:
			print 'Try again:',fname
			exit()
		j=1
		for line in fhand:
			if (j>old):
				if line.startswith('<'):
					linenum=line.find(">")
					function=line[linenum+2:]
					if function.startswith('!test '):
						letterChosen=line[linenum+8]
						if(letterChosen>='A' and letterChosen <='Z'):
							letterChosen=letterChosen.lower()
						if(letterChosen>='a' and letterChosen<='z'):
							try:
								a=wordChosen.index(letterChosen)
							except ValueError:
								try:
									a=badLetters.index(letterChosen)
								except ValueError:
									badLetters+=letterChosen
									hangmanCounter+=1
									print '!'
									print 'B'
									print letterChosen
									#ser.write('!')
									#ser.write('B')
									#ser.write(letterChosen)
									if (hangmanCounter>=10):
										hangmanCounter=0
										hangmanStarted=0
										#time.sleep(30)
										break
							try:
								a=usedLetters.index(letterChosen)
							except ValueError:
								k=0
								usedLetters+=letterChosen
								for char in wordChosen:
									if(letterChosen==char):
										print '!'
										print k
										print letterChosen
										#ser.write('!')
										#ser.write(k)
										#ser.write(letterChosen)
										#wordChosen[k]='0'
									k+=1
					elif function.startswith('!answer '):
						if function.startswith('!answer '+wordChosen):
							print '!'
							print '%'
							#ser.write('!')
							#ser.write('%')
						else:
							print '!'
							print '^'
							#ser.write('!')
							#ser.write('^')
					elif function.startswith('!switchset 1'):
						if line.startswith('<beatrng>'):
							print '!'
							print '~'
							#ser.write('!')
							#ser.write('~')
							modeselect=1
				old=old+1
			j=j+1
		fhand.close()
exit()