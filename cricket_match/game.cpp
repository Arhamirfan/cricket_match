COMMENT ! remember to install irvine32 library to run this code in Visual studio !

COMMENT !--This project is created by Arham Irfan from FAST-NU university !

INCLUDE Irvine32.inc

.data

sashka BYTE " --------------------------------------------------", 0
finalstartingmsg BYTE " ______________Final is about to start_____________", 0
verses BYTE "    vs    ", 0
scoreboard BYTE " ******************* SCOREBOARD *******************", 0
semifinalone BYTE " 1st SEMI FINAL IS STARTED (-> HOLD YOUR BREATH MATCH IS STARTED <-) ", 0
semifinaltwo BYTE " 2nd SEMI FINAL IS STARTED (-> HOLD YOUR BREATH MATCH IS STARTED <-) ", 0
started BYTE " ...MATCH STARTED AND THE 1ST BALL IS PLAYED...", 0
playername BYTE " NAME ", 0
playerscore byte " SCORE ", 0
ballsplayedmsg BYTE " BALLS ", 0
sixesmsg BYTE " 6's ", 0
foursmsg byte " 4's ", 0
extrasmsg BYTE " Extra's : ", 0
teamone BYTE   " TEAM 1 : ", 0
teamtwo BYTE   " TEAM 2 : ", 0
teamthree BYTE " TEAM 3 : ", 0
teamfour BYTE  " TEAM 4 : ", 0
overone BYTE " OVER ONE : ", 0
overtwo BYTE " OVER TWO : ", 0
overthree BYTE " OVER THREE : ", 0
overfour BYTE " OVER FOUR : ", 0

takingnames BYTE " Enter team player name : ", 0
winner BYTE "  WINNING TEAM IS :  ", 0

fieldselectionmsg byte " Wins the toss .. Select one (0. To bat || 1. To ball ) : ", 0
zeromsg BYTE " 0 run ,with a TUK TUK", 0
fourmsg BYTE    " 4 runs , IT'S A FOUR .. what a shot  ", 0
sixmsg byte     " 6 runs , AND AN AMAZING SIXER .. chah gye ustaad  ", 0
extramsg byte   " 1 run , A WIDE BALL .. baller is confused ", 0
outmsg byte		" WICKET , HE'S GONE WITH A STUMP .. amazing ball ", 0
winningmsg BYTE " .. team wins by luck :p ", 0
endedmsg byte " Match ended (DUE TO RAIN) :p ", 0
endingmsg BYTE " THANKS FOR WATCHING FAST CRICKET MATCH.....(NOW YOU CAN GO HOME -_-)", 0
tossingmsg BYTE " Enter 1. to toss coin || 0. to end match : ", 0
tosscoin byte 0
tossing byte 0
bat_ball byte 0


team1name BYTE 100 DUP(? )
team1player1name byte 100 DUP(? )
team1player2name byte 100 DUP(? )
team1player3name byte 100 DUP(? )
team1player4name byte 100 DUP(? )

team2name BYTE 100 DUP(? )
team2player1name byte 100 DUP(? )
team2player2name byte 100 DUP(? )
team2player3name byte 100 DUP(? )
team2player4name byte 100 DUP(? )

team3name BYTE 100 DUP(? )
team3player1name byte 100 DUP(? )
team3player2name byte 100 DUP(? )
team3player3name byte 100 DUP(? )
team3player4name byte 100 DUP(? )

team4name BYTE 100 DUP(? )
team4player1name byte 100 DUP(? )
team4player2name byte 100 DUP(? )
team4player3name byte 100 DUP(? )
team4player4name byte 100 DUP(? )

team1playersscore BYTE 4 DUP(0)
team2playersscore BYTE 4 DUP(0)
team3playersscore BYTE 4 DUP(0)
team4playersscore BYTE 4 DUP(0)

team16counter BYTE 4 DUP(0)
team26counter BYTE 4 DUP(0)
team36counter BYTE 4 DUP(0)
team46counter BYTE 4 DUP(0)

team14counter BYTE 4 DUP(0)
team24counter BYTE 4 DUP(0)
team34counter BYTE 4 DUP(0)
team44counter BYTE 4 DUP(0)

team1ballcounter BYTE 4 DUP(0)
team2ballcounter BYTE 4 DUP(0)
team3ballcounter BYTE 4 DUP(0)
team4ballcounter BYTE 4 DUP(0)

team1totalscore  BYTE 0
team2totalscore  BYTE 0
team3totalscore  BYTE 0
team4totalscore  BYTE 0

team13winnercounter BYTE 10
team24winnercounter BYTE 10
finalwinner BYTE 100 DUP(? )
overcounter BYTE 0
extracounter BYTE 0



.code
main PROC
xor eax, eax
xor edx, edx
xor esi, esi

COMMENT !---------------------------------- - TEAM 1 / TEAM 3 SEMI FINAL  MATCH---------------------------- - !

call crlf
mov edx, OFFSET semifinalone
call writestring
call crlf
call crlf
mov eax, 2000
call Delay

call crlf
call inserting_team1
call crlf
call inserting_team3

XOR eax, eax
mov edx, OFFSET tossingmsg
call WriteString
call readint
mov tosscoin, al

cmp eax, 0
jg continuematch
jz endmatch

continuematch :
call toss


call crlf
mov edx, OFFSET sashka
call writestring
call crlf
mov al, 9
call writechar
mov edx, OFFSET team1name
call writestring
mov edx, OFFSET verses
call writestring
mov edx, OFFSET team3name
call writestring
call crlf
mov edx, OFFSET sashka
call writestring
call crlf
call crlf
call crlf

mov al, tossing
cmp eax, 0
jg team1wins
jz team3wins

team1wins :

mov edx, OFFSET teamone
call writestring
mov edx, OFFSET fieldselectionmsg
call writestring
call readint
mov bat_ball, al
cmp eax, 0
jg team3bat
jz team1bat

COMMENT !-------------------------------- - TEAM 1 WINS TOSS AND SELECTS BAT------------------------ !

team1bat :

mov edx, OFFSET teamone
call writestring
call team1batting
xor eax, eax
xor esi, esi
call team3batting
xor eax, eax
xor esi, esi
jmp semiwinner

COMMENT !-------------------------------- - TEAM 1 WINS TOSS AND SELECTS BALL------------------------ !

team3bat:


call team3batting
call team1batting

jmp semiwinner

team3wins :

mov edx, OFFSET teamthree
call writestring
mov edx, OFFSET fieldselectionmsg
call writestring
call readint
mov bat_ball, al
cmp eax, 0

COMMENT !-------------------------------- - TEAM 3 WINS TOSS AND CALLS PREVIOUS BAT / BALL FUNCTIONS------------------------ !

jg team1bat
jz team3bat



endmatch:
mov edx, OFFSET endedmsg
call writestring

COMMENT !---------------------------------- - TEAM 1 / TEAM 3 DISPLAYING TOTAL SCORES---------------------------- - !

semiwinner :

	mov edx, OFFSET sashka
	call writestring
	call crlf
	mov edx, OFFSET scoreboard
	call writestring
	call crlf
	call crlf
	mov al, 9
	call writechar
	mov edx, OFFSET team3name
	call writestring
	mov al, team3totalscore
	call writeint
	mov al, 9
	call writechar
	mov edx, OFFSET team1name
	call writestring
	mov al, team1totalscore
	call writeint
	call crlf
	call crlf

	COMMENT !---------------------------------- - TEAM 1 / TEAM 3 DISPLAYING TOTAL SCORES---------------------------- - !

	mov  edx, OFFSET winner
	call writestring

	cmp al, team3totalscore
	jge team1finalist
	jb team3finalist


	COMMENT !---------------------------------- - TEAM 1 SEMI - WINNER---------------------------- - !

	team1finalist :

mov edx, OFFSET team1name
call writestring
call crlf
mov edx, OFFSET sashka
call writestring

mov team13winnercounter, 0

jmp semifinal2


COMMENT !---------------------------------- - TEAM 3 SEMI - WINNER---------------------------- - !


team3finalist :

mov edx, OFFSET team3name
call writestring
call crlf
mov edx, OFFSET sashka
call writestring

mov team13winnercounter, 1

jmp semifinal2





COMMENT !---------------------------------- - TEAM 2 / TEAM 4 SEMI FINAL  MATCH---------------------------- - !

semifinal2:

call crlf
call WaitMsg
call crlf
call clrscr
call crlf
mov edx, OFFSET sashka
call writestring
call crlf

mov edx, OFFSET semifinaltwo
call writestring

call crlf
call crlf
mov edx, OFFSET sashka
call writestring
call crlf

mov eax, 2000
call Delay


COMMENT !---------------------------------- - TEAM 2, 4  INSERTING NAMES---------------------------- - !

call crlf
call inserting_team2
call crlf
call inserting_team4

XOR eax, eax
mov edx, OFFSET tossingmsg
call WriteString
call readint
mov tosscoin, al

cmp eax, 0
jg continuematch1
jz endmatch1

continuematch1 :
call toss



call crlf
mov edx, OFFSET sashka
call writestring
call crlf
mov al, 9
call writechar
mov edx, OFFSET team2name
call writestring
mov edx, OFFSET verses
call writestring
mov edx, OFFSET team4name
call writestring
call crlf
mov edx, OFFSET sashka
call writestring
call crlf
call crlf
call crlf



mov al, tossing
cmp eax, 0
jg team2wins
jz team4wins

team2wins :

mov edx, OFFSET teamtwo
call writestring
mov edx, OFFSET fieldselectionmsg
call writestring
call readint
mov bat_ball, al
cmp eax, 0
jg team4bat
jz team2bat

COMMENT !-------------------------------- - TEAM 2 WINS TOSS AND SELECTS BAT------------------------ !

team2bat :

mov edx, OFFSET teamone
call writestring
call team2batting
call team4batting
jmp semiwinner1

COMMENT !-------------------------------- - TEAM 2 WINS TOSS AND SELECTS BALL------------------------ !

team4bat:

mov edx, OFFSET teamfour
call writestring
call team4batting
call team2batting
jmp semiwinner1

team4wins :

mov edx, OFFSET teamfour
call writestring
mov edx, OFFSET fieldselectionmsg
call writestring
call readint
mov bat_ball, al
cmp eax, 0

COMMENT !-------------------------------- - TEAM 4 WINS TOSS AND CALLS PREVIOUS BAT / BALL FUNCTIONS------------------------ !

jg team2bat
jz team4bat



endmatch1:
mov edx, OFFSET endedmsg
call writestring

COMMENT !---------------------------------- - TEAM 2 / TEAM 4 DISPLAYING TOTAL SCORES---------------------------- - !

semiwinner1 :

	mov edx, OFFSET sashka
	call writestring
	call crlf
	mov edx, OFFSET scoreboard
	call writestring
	call crlf
	call crlf
	mov al, 9
	call writechar
	mov edx, OFFSET team4name
	call writestring
	mov al, team4totalscore
	call writeint
	mov al, 9
	call writechar
	mov edx, OFFSET team2name
	call writestring
	mov al, team2totalscore
	call writeint
	call crlf
	call crlf

	COMMENT !---------------------------------- - TEAM 2 / TEAM 4 DISPLAYING TOTAL SCORES---------------------------- - !

	mov  edx, OFFSET winner
	call writestring

	cmp al, team4totalscore
	jge team2finalist
	jb team4finalist


	COMMENT !---------------------------------- - TEAM 2 SEMI - WINNER---------------------------- - !

	team2finalist :

mov edx, OFFSET team2name
call writestring
call crlf
mov edx, OFFSET sashka
call writestring

mov team24winnercounter, 0

jmp finalmatch


COMMENT !---------------------------------- - TEAM 4 SEMI - WINNER---------------------------- - !

team4finalist :

mov edx, OFFSET team4name
call writestring
call crlf
mov edx, OFFSET sashka
call writestring

mov team24winnercounter, 1

jmp finalmatch


COMMENT !------------------------------------------------ - -FINAL MATCH STARTING-------------------------------------------- - !


finalmatch:

call crlf
call WaitMsg
call clrscr

call crlf

mov edx, OFFSET sashka
call writestring
call crlf
mov edx, OFFSET finalstartingmsg
call writestring

XOR eax, eax
XOR edx, edx
mov team1totalscore, 0
mov team2totalscore, 0
mov team3totalscore, 0
mov team4totalscore, 0


mov al, team13winnercounter
cmp al, team24winnercounter
je bothoneorzero
jne bothopposite

bothoneorzero :

mov al, team13winnercounter
cmp al, 0
je team12finalist
jne team34finalist
COMMENT !------------------ - FINALS B / W TEAM 1 AND TEAM 2         ----------------------!
team12finalist:


call crlf
mov edx, OFFSET sashka
call writestring
call crlf
mov al, 9
call writechar
mov edx, OFFSET team1name
call writestring
mov edx, OFFSET verses
call writestring
mov edx, OFFSET team2name
call writestring
call crlf
mov edx, OFFSET sashka
call writestring
call crlf
call crlf
call crlf

call team1batting
call team2batting







COMMENT !---------------------------------- - TEAM 1 / TEAM 2 DISPLAYING TOTAL SCORES---------------------------- - !

mov edx, OFFSET sashka
call writestring
call crlf
mov edx, OFFSET scoreboard
call writestring
call crlf
call crlf
mov al, 9
call writechar
mov edx, OFFSET team1name
call writestring
mov al, team1totalscore
call writeint
mov al, 9
call writechar
mov edx, OFFSET team2name
call writestring
mov al, team2totalscore
call writeint
call crlf
call crlf

COMMENT !---------------------------------- - TEAM 2 / TEAM 4 DISPLAYING TOTAL SCORES---------------------------- - !

mov  edx, OFFSET winner
call writestring

cmp al, team1totalscore
jge team2finalwinner
jb team1finalwinner


COMMENT !---------------------------------- - TEAM 2 winner - WINNER---------------------------- - !

team2finalwinner :

mov edx, OFFSET team2name
call writestring
call crlf
mov edx, OFFSET sashka
call writestring
INVOKE Str_copy,
ADDR team2name,
ADDR finalwinner
jmp finalscore


COMMENT !---------------------------------- - TEAM 1 winner - WINNER---------------------------- - !

team1finalwinner :

mov edx, OFFSET team1name
call writestring
call crlf
mov edx, OFFSET sashka
call writestring
INVOKE Str_copy,
ADDR team1name,
ADDR finalwinner



jmp finalscore



COMMENT !------------------ - FINALS B / W TEAM 3 AND TEAM 4         ----------------------!

team34finalist:

call crlf
mov edx, OFFSET sashka
call writestring
call crlf
mov al, 9
call writechar
mov edx, OFFSET team3name
call writestring
mov edx, OFFSET verses
call writestring
mov edx, OFFSET team4name
call writestring
call crlf
mov edx, OFFSET sashka
call writestring
call crlf
call crlf
call crlf

call team3batting
call team4batting


COMMENT !---------------------------------- - TEAM 3 / TEAM 4 DISPLAYING TOTAL SCORES---------------------------- - !

mov edx, OFFSET sashka
call writestring
call crlf
mov edx, OFFSET scoreboard
call writestring
call crlf
call crlf
mov al, 9
call writechar
mov edx, OFFSET team3name
call writestring
mov al, team3totalscore
call writeint
mov al, 9
call writechar
mov edx, OFFSET team4name
call writestring
mov al, team4totalscore
call writeint
call crlf
call crlf

COMMENT !---------------------------------- - TEAM 3 / TEAM 4 DISPLAYING TOTAL SCORES---------------------------- - !

mov  edx, OFFSET winner
call writestring

cmp al, team3totalscore
jge team4finalwinner
jb team3finalwinner


COMMENT !---------------------------------- - TEAM 3 winner - WINNER---------------------------- - !

team4finalwinner :

mov edx, OFFSET team4name
call writestring
call crlf
mov edx, OFFSET sashka
call writestring
INVOKE Str_copy,
ADDR team4name,
ADDR finalwinner

jmp finalscore

COMMENT !---------------------------------- - TEAM 4 winner - WINNER---------------------------- - !

team3finalwinner :

mov edx, OFFSET team3name
call writestring
call crlf
mov edx, OFFSET sashka
call writestring
INVOKE Str_copy,
ADDR team3name,
ADDR finalwinner


jmp finalscore




bothopposite:


mov al, team13winnercounter
cmp al, 0
je team14finalist1
jne team32finalist1


team14finalist1 :


call crlf
mov edx, OFFSET sashka
call writestring
call crlf
mov al, 9
call writechar
mov edx, OFFSET team1name
call writestring
mov edx, OFFSET verses
call writestring
mov edx, OFFSET team4name
call writestring
call crlf
mov edx, OFFSET sashka
call writestring
call crlf
call crlf
call crlf

call team1batting
call team4batting







COMMENT !---------------------------------- - TEAM 1 / TEAM 4 DISPLAYING TOTAL SCORES---------------------------- - !

mov edx, OFFSET sashka
call writestring
call crlf
mov edx, OFFSET scoreboard
call writestring
call crlf
call crlf
mov al, 9
call writechar
mov edx, OFFSET team1name
call writestring
mov al, team1totalscore
call writeint
mov al, 9
call writechar
mov edx, OFFSET team4name
call writestring
mov al, team4totalscore
call writeint
call crlf
call crlf

COMMENT !---------------------------------- - TEAM 1 / TEAM 4 DISPLAYING TOTAL SCORES---------------------------- - !

mov  edx, OFFSET winner
call writestring

cmp al, team1totalscore
jge team4finalwinner
jb team1finalwinner







team32finalist1:




call crlf
mov edx, OFFSET sashka
call writestring
call crlf
mov al, 9
call writechar
mov edx, OFFSET team2name
call writestring
mov edx, OFFSET verses
call writestring
mov edx, OFFSET team3name
call writestring
call crlf
mov edx, OFFSET sashka
call writestring
call crlf
call crlf
call crlf

call team1batting
call team4batting







COMMENT !---------------------------------- - TEAM 2 / TEAM 3 DISPLAYING TOTAL SCORES---------------------------- - !

mov edx, OFFSET sashka
call writestring
call crlf
mov edx, OFFSET scoreboard
call writestring
call crlf
call crlf
mov al, 9
call writechar
mov edx, OFFSET team3name
call writestring
mov al, team3totalscore
call writeint
mov al, 9
call writechar
mov edx, OFFSET team2name
call writestring
mov al, team2totalscore
call writeint
call crlf
call crlf

COMMENT !---------------------------------- - TEAM 2 / TEAM 3 DISPLAYING TOTAL SCORES---------------------------- - !

mov  edx, OFFSET winner
call writestring

cmp al, team3totalscore
jge team2finalwinner
jb team3finalwinner







finalscore:
call crlf
call crlf
call crlf
mov al, 9
call writechar
mov edx, OFFSET sashka
call writestring
call crlf
mov al, 9
call writechar
mov edx, OFFSET winner
call writestring

mov al, 9
call writechar
mov edx, OFFSET finalwinner
call writestring
call  crlf
call crlf
mov al, 9
call writechar
mov edx, offset endingmsg
call writestring
call crlf
call crlf
mov al, 9
call writechar
mov edx, OFFSET sashka
call writestring

endprogram :
call crlf
exit
main ENDP















COMMENT !---------------------------------- - TOSS FUNCTION---------------------------- - !

toss PROC
call Randomize
mov eax, 2
call RandomRange
mov tossing, al
ret
toss endp







COMMENT !---------------------------------- - TEAM 1 TAKING NAMES---------------------------- - !

inserting_team1 PROC

mov edx, OFFSET teamone
call Writestring
mov edx, OFFSET team1name
mov ecx, SIZEOF team1name
call ReadString

mov edx, OFFSET takingnames
call writestring
mov edx, OFFSET team1player1name
call ReadString

mov edx, OFFSET takingnames
call writestring
mov edx, OFFSET team1player2name
call ReadString

mov edx, OFFSET takingnames
call writestring
mov edx, OFFSET team1player3name
call ReadString

mov edx, OFFSET takingnames
call writestring
mov edx, OFFSET team1player4name
call ReadString

ret
inserting_team1 endp





COMMENT !---------------------------------- - TEAM 3 TAKING NAMES---------------------------- - !


inserting_team3 PROC

mov edx, OFFSET teamthree
call Writestring
mov edx, OFFSET team3name
mov ecx, SIZEOF team3name
call ReadString

mov edx, OFFSET takingnames
call writestring
mov edx, OFFSET team3player1name
call ReadString

mov edx, OFFSET takingnames
call writestring
mov edx, OFFSET team3player2name
call ReadString

mov edx, OFFSET takingnames
call writestring
mov edx, OFFSET team3player3name
call ReadString

mov edx, OFFSET takingnames
call writestring
mov edx, OFFSET team3player4name
call ReadString
call crlf


ret
inserting_team3 endp







COMMENT !---------------------------------- - TEAM 2 TAKING NAMES---------------------------- - !


inserting_team2 PROC

mov edx, OFFSET teamtwo
call Writestring
mov edx, OFFSET team2name
mov ecx, SIZEOF team2name
call ReadString

mov edx, OFFSET takingnames
call writestring
mov edx, OFFSET team2player1name
call ReadString

mov edx, OFFSET takingnames
call writestring
mov edx, OFFSET team2player2name
call ReadString

mov edx, OFFSET takingnames
call writestring
mov edx, OFFSET team2player3name
call ReadString

mov edx, OFFSET takingnames
call writestring
mov edx, OFFSET team2player4name
call ReadString

call crlf

ret
inserting_team2 endp







COMMENT !---------------------------------- - TEAM 4 TAKING NAMES---------------------------- - !


inserting_team4 PROC

mov edx, OFFSET teamfour
call Writestring
mov edx, OFFSET team4name
mov ecx, SIZEOF team4name
call ReadString

mov edx, OFFSET takingnames
call writestring
mov edx, OFFSET team4player1name
call ReadString

mov edx, OFFSET takingnames
call writestring
mov edx, OFFSET team4player2name
call ReadString

mov edx, OFFSET takingnames
call writestring
mov edx, OFFSET team4player3name
call ReadString

mov edx, OFFSET takingnames
call writestring
mov edx, OFFSET team4player4name
call ReadString

call crlf

ret
inserting_team4 endp








COMMENT !---------------------------------- - TEAM 1 BATTING---------------------------- - !

team1batting PROC

mov esi, 4
clearingvariables:
mov extracounter, 0
mov team1playersscore[esi], 0
mov team16counter[esi], 0
mov team14counter[esi], 0

DEC esi
jnz clearingvariables

call crlf
mov edx, OFFSET sashka
call writestring
call crlf
mov edx, OFFSET started
call writestring
call crlf
mov edx, OFFSET sashka
call writestring
call crlf
call crlf





COMMENT !---------------------------------- - 2D LOOP FOR ADDITION OF RUNS ON OVERS AND BALLS---------------------------- - !



mov esi, 0
mov ecx, 18
call Randomize

batingloop :



cmp ecx, 18
je firstover
jb moreovers
jmp continuebatting

firstover :
call crlf
mov edx, OFFSET overone
call writestring
call crlf
jmp continuebatting


moreovers :
cmp ecx, 12
je secondover
jb moreover1
jmp continuebatting

secondover :
call crlf
mov edx, OFFSET overtwo
call writestring
call crlf
jmp continuebatting

moreover1 :
cmp ecx, 6
je thirdover
jmp continuebatting


thirdover :
call crlf
mov edx, OFFSET overthree
call writestring
call crlf
jmp continuebatting


continuebatting :

cmp esi, 4
je noplayersleft1
jmp conti

noplayersleft1 :
jmp outofloop

conti :
mov eax, 4
ADD eax, 1
call RandomRange


cmp eax, 1
je onerun
jg morethenone

onerun :
mov al, 4
ADD team1playersscore[esi], al
ADD team1totalscore, al
ADD team1ballcounter[esi], 1
ADD team14counter[esi], 1
mov edx, OFFSET fourmsg
call writestring
call crlf
jmp endbattingloop

morethenone :
cmp eax, 2
je tworun
jg morethentwo

tworun :
mov al, 6
ADD team1playersscore[esi], al
ADD team1totalscore, al
ADD team16counter[esi], 1
ADD team1ballcounter[esi], 1
mov edx, OFFSET sixmsg
call writestring
call crlf
jmp endbattingloop

morethentwo :
cmp eax, 3
je threerun
jg morethenthree

threerun :
mov al, 1
ADD team1playersscore[esi], al
ADD team1totalscore, al
ADD team1ballcounter[esi], 1
INC extracounter
INC ecx
mov al, 9
call writechar
mov edx, OFFSET extramsg
call writestring
call crlf
jmp endbattingloop

morethenthree :
ADD esi, 1
mov edx, OFFSET outmsg
call writestring
call crlf

endbattingloop :


DEC ecx
jnz batingloop




COMMENT !---------------------------------- - PRINTING TEAM 1 FINAL RESULT OF PLAYERS---------------------------- - !

outofloop:

xor esi, esi

call crlf
mov edx, OFFSET sashka
call writestring
call crlf
call crlf

mov edx, OFFSET scoreboard
call writestring
call crlf

mov edx, OFFSET playername
call writestring

mov al, 9
call writechar

mov edx, offset ballsplayedmsg
call writestring

mov al, 9
call writechar

mov edx, OFFSET foursmsg
call writestring

mov al, 9
call writechar

mov edx, offset sixesmsg
call writestring

mov al, 9
call writechar

mov edx, OFFSET playerscore
call writestring
call crlf



mov edx, OFFSET team1player1name
call writestring

mov al, 9
call writechar

mov al, team1ballcounter[0]
call writeint

mov al, 9
call writechar

mov al, team14counter[0]
call writeint

mov al, 9
call writechar

mov al, team16counter[0]
call writeint

mov al, 9
call writechar

mov al, team1playersscore[0]
call writeint
call crlf

mov edx, OFFSET team1player2name
call writestring

mov al, 9
call writechar

mov al, team1ballcounter[1]
call writeint

mov al, 9
call writechar

mov al, team14counter[1]
call writeint

mov al, 9
call writechar

mov al, team16counter[1]
call writeint

mov al, 9
call writechar

mov al, team1playersscore[1]
call writeint
call crlf

mov edx, OFFSET team1player3name
call writestring

mov al, 9
call writechar

mov al, team1ballcounter[2]
call writeint

mov al, 9
call writechar

mov al, team14counter[2]
call writeint

mov al, 9
call writechar

mov al, team16counter[2]
call writeint

mov al, 9
call writechar

mov al, team1playersscore[2]
call writeint
call crlf

mov edx, OFFSET team1player4name
call writestring

mov al, 9
call writechar

mov al, team1ballcounter[3]
call writeint

mov al, 9
call writechar

mov al, team14counter[3]
call writeint

mov al, 9
call writechar

mov al, team16counter[3]
call writeint

mov al, 9
call writechar

mov al, team1playersscore[3]
call writeint
call crlf
mov edx, OFFSET extrasmsg
call writestring
mov al, extracounter
call writeint
call crlf
call crlf


mov al, 9
call writechar
mov edx, OFFSET team1name
call writestring

mov edx, OFFSET playerscore
call writestring

mov al, team1totalscore
call writeint
call crlf




COMMENT !---------------------------------- - TEAM 1 BATTING ENDS---------------------------- - !

endteam1turn:
ret
team1batting ENDP












team2batting PROC



mov esi, 4
clearingvariables:
mov extracounter, 0
mov team2playersscore[esi], 0
mov team26counter[esi], 0
mov team24counter[esi], 0
DEC esi
jnz clearingvariables



call crlf
mov edx, OFFSET sashka
call writestring
call crlf
mov edx, OFFSET started
call writestring
call crlf
mov edx, OFFSET sashka
call writestring
call crlf
call crlf




COMMENT !---------------------------------- - 2D LOOPS FOR ADDITION OF SCORES BOTH OVERS AND BALLS---------------------------- - !



mov esi, 0
mov ecx, 18
call Randomize

batingloop :


cmp ecx, 18
je firstover
jb moreovers
jmp continuebatting

firstover :
call crlf
mov edx, OFFSET overone
call writestring
call crlf
jmp continuebatting


moreovers :
cmp ecx, 12
je secondover
jb moreover1
jmp continuebatting

secondover :
call crlf
mov edx, OFFSET overtwo
call writestring
call crlf
jmp continuebatting

moreover1 :
cmp ecx, 6
je thirdover
jmp continuebatting


thirdover :
call crlf
mov edx, OFFSET overthree
call writestring
call crlf
jmp continuebatting


continuebatting :

cmp esi, 4
je noplayersleft1
jmp conti

noplayersleft1 :
jmp outofloop

conti :
mov eax, 5
ADD eax, 1
call RandomRange

cmp eax, 1
je onerun
jg morethenone

onerun :
mov al, 4
ADD team2playersscore[esi], al
ADD team2totalscore, al
ADD team2ballcounter[esi], 1
ADD team24counter[esi], 1
mov edx, OFFSET fourmsg
call writestring
call crlf
jmp endbattingloop

morethenone :
cmp eax, 2
je tworun
jg morethentwo

tworun :
mov al, 6
ADD team2playersscore[esi], al
ADD team2totalscore, al
ADD team26counter[esi], 1
ADD team2ballcounter[esi], 1
mov edx, OFFSET sixmsg
call writestring
call crlf
jmp endbattingloop

morethentwo :
cmp eax, 3
je threerun
jg morethenthree

threerun :
mov al, 1
ADD team2playersscore[esi], al
ADD team2totalscore, al
ADD team2ballcounter[esi], 1
INC extracounter
INC ecx
mov al, 9
call writechar
mov edx, OFFSET extramsg
call writestring
call crlf
jmp endbattingloop

morethenthree :
ADD esi, 1
mov edx, OFFSET outmsg
call writestring
call crlf

endbattingloop :

DEC ecx
jnz batingloop


outofloop :

COMMENT !---------------------------------- - TEAM 2 FINAL RESULT OF PLAYERS---------------------------- - !
xor esi, esi
call crlf

mov edx, OFFSET sashka
call writestring
call crlf
call crlf

mov edx, OFFSET scoreboard
call writestring
call crlf

mov edx, OFFSET playername
call writestring

mov al, 9
call writechar

mov edx, offset ballsplayedmsg
call writestring

mov al, 9
call writechar

mov edx, offset foursmsg
call writestring

mov al, 9
call writechar

mov edx, offset sixesmsg
call writestring

mov al, 9
call writechar

mov edx, OFFSET playerscore
call writestring
call crlf

mov edx, OFFSET team2player1name
call writestring

mov al, 9
call writechar

mov al, team2ballcounter[0]
call writeint

mov al, 9
call writechar

mov al, team24counter[0]
call writeint

mov al, 9
call writechar

mov al, team26counter[0]
call writeint

mov al, 9
call writechar

mov al, team2playersscore[0]
call writeint
call crlf

mov edx, OFFSET team2player2name
call writestring

mov al, 9
call writechar

mov al, team2ballcounter[1]
call writeint

mov al, 9
call writechar

mov al, team24counter[1]
call writeint

mov al, 9
call writechar

mov al, team26counter[1]
call writeint

mov al, 9
call writechar

mov al, team2playersscore[1]
call writeint
call crlf

mov edx, OFFSET team2player3name
call writestring

mov al, 9
call writechar

mov al, team2ballcounter[2]
call writeint

mov al, 9
call writechar

mov al, team24counter[2]
call writeint

mov al, 9
call writechar

mov al, team26counter[2]
call writeint

mov al, 9
call writechar

mov al, team2playersscore[2]
call writeint
call crlf

mov edx, OFFSET team2player4name
call writestring

mov al, 9
call writechar

mov al, team2ballcounter[3]
call writeint

mov al, 9
call writechar

mov al, team24counter[3]
call writeint

mov al, 9
call writechar

mov al, team26counter[3]
call writeint

mov al, 9
call writechar

mov al, team2playersscore[3]
call writeint
call crlf
call crlf
mov edx, OFFSET extrasmsg
call writestring
mov al, extracounter
call writeint
call crlf
call crlf


mov al, 9
call writechar
mov edx, OFFSET team2name
call writestring

mov edx, OFFSET playerscore
call writestring

mov al, team2totalscore
call writeint
call crlf
call crlf
endteam2turn :

COMMENT !---------------------------------- - TEAM 2 BATTING ENDS---------------------------- - !

ret
team2batting ENDP








team3batting PROC


mov esi, 4
clearingvariables:
mov extracounter, 0
mov team3playersscore[esi], 0
mov team36counter[esi], 0
mov team34counter[esi], 0
DEC esi
jnz clearingvariables



call crlf
mov edx, OFFSET sashka
call writestring
call crlf
mov edx, OFFSET started
call writestring
call crlf
mov edx, OFFSET sashka
call writestring
call crlf
call crlf




COMMENT !---------------------------------- - 2D LOOPS FOR ADDITION OF SCORES BOTH OVERS AND BALLS---------------------------- - !



mov esi, 0
mov ecx, 18
call Randomize

batingloop :



cmp ecx, 18
je firstover
jb moreovers
jmp continuebatting

firstover :
call crlf
mov edx, OFFSET overone
call writestring
call crlf
jmp continuebatting


moreovers :
cmp ecx, 12
je secondover
jb moreover1
jmp continuebatting

secondover :
call crlf
mov edx, OFFSET overtwo
call writestring
call crlf
jmp continuebatting

moreover1 :
cmp ecx, 6
je thirdover
jmp continuebatting


thirdover :
call crlf
mov edx, OFFSET overthree
call writestring
call crlf
jmp continuebatting


continuebatting :



cmp esi, 4
je noplayersleft1
jmp conti

noplayersleft1 :
jmp outofloop

conti :
mov eax, 4
ADD eax, 1
call RandomRange

cmp eax, 1
je onerun
jg morethenone

onerun :
mov al, 4
ADD team3playersscore[esi], al
ADD team3totalscore, al
ADD team3ballcounter[esi], 1
ADD team34counter[esi], 1
mov edx, OFFSET fourmsg
call writestring
call crlf
jmp endbattingloop

morethenone :
cmp eax, 2
je tworun
jg morethentwo

tworun :
mov al, 6
ADD team3playersscore[esi], al
ADD team3totalscore, al
ADD team36counter[esi], 1
ADD team3ballcounter[esi], 1
mov edx, OFFSET sixmsg
call writestring
call crlf
jmp endbattingloop

morethentwo :
cmp eax, 3
je threerun
jg morethenthree

threerun :
mov al, 1
ADD team3playersscore[esi], al
ADD team3totalscore, al
ADD team36counter[esi], 1
ADD team3ballcounter[esi], 1
INC extracounter
INC ecx
mov al, 9
call writechar
mov edx, OFFSET extramsg
call writestring
call crlf
jmp endbattingloop

morethenthree :
ADD esi, 1
mov edx, OFFSET outmsg
call writestring
call crlf

endbattingloop :

DEC ecx
jnz batingloop


outofloop :

COMMENT !---------------------------------- - TEAM 3 FINAL RESULT OF PLAYERS---------------------------- - !


call crlf
xor esi, esi
mov edx, OFFSET sashka
call writestring
call crlf
call crlf

mov edx, OFFSET scoreboard
call writestring
call crlf

mov edx, OFFSET playername
call writestring

mov al, 9
call writechar

mov edx, offset ballsplayedmsg
call writestring

mov al, 9
call writechar

mov edx, offset foursmsg
call writestring

mov al, 9
call writechar

mov edx, offset sixesmsg
call writestring

mov al, 9
call writechar

mov edx, OFFSET playerscore
call writestring
call crlf

mov edx, OFFSET team3player1name
call writestring

mov al, 9
call writechar

mov al, team3ballcounter[0]
call writeint

mov al, 9
call writechar

mov al, team34counter[0]
call writeint

mov al, 9
call writechar

mov al, team36counter[0]
call writeint

mov al, 9
call writechar

mov al, team3playersscore[0]
call writeint
call crlf

mov edx, OFFSET team3player2name
call writestring

mov al, 9
call writechar

mov al, team3ballcounter[1]
call writeint

mov al, 9
call writechar

mov al, team34counter[1]
call writeint

mov al, 9
call writechar

mov al, team36counter[1]
call writeint

mov al, 9
call writechar

mov al, team3playersscore[1]
call writeint
call crlf

mov edx, OFFSET team3player3name
call writestring

mov al, 9
call writechar

mov al, team3ballcounter[2]
call writeint

mov al, 9
call writechar

mov al, team34counter[2]
call writeint

mov al, 9
call writechar

mov al, team36counter[2]
call writeint

mov al, 9
call writechar

mov al, team3playersscore[2]
call writeint
call crlf

mov edx, OFFSET team3player4name
call writestring

mov al, 9
call writechar

mov al, team3ballcounter[3]
call writeint

mov al, 9
call writechar

mov al, team36counter[3]
call writeint

mov al, 9
call writechar

mov al, team36counter[3]
call writeint

mov al, 9
call writechar

mov al, team3playersscore[3]
call writeint
call crlf
call crlf
mov edx, OFFSET extrasmsg
call writestring
mov al, extracounter
call writeint
call crlf


mov al, 9
call writechar
mov edx, OFFSET team3name
call writestring

mov edx, OFFSET playerscore
call writestring

mov al, team3totalscore
call writeint
call crlf


endteam3turn :

COMMENT !---------------------------------- - TEAM 3 BATTING ENDS---------------------------- - !

ret
team3batting ENDP









team4batting PROC


mov esi, 4
clearingvariables:
mov extracounter, 0
mov team4playersscore[esi], 0
mov team46counter[esi], 0
mov team44counter[esi], 0

DEC esi
jnz clearingvariables

call crlf
mov edx, OFFSET sashka
call writestring
call crlf
mov edx, OFFSET started
call writestring
call crlf
mov edx, OFFSET sashka
call writestring
call crlf
call crlf




COMMENT !---------------------------------- - 2D LOOPS FOR ADDITION OF SCORES BOTH OVERS AND BALLS---------------------------- - !


mov esi, 0
mov ecx, 18
call Randomize
batingloop :


cmp ecx, 18
je firstover
jb moreovers
jmp continuebatting

firstover :
call crlf
mov edx, OFFSET overone
call writestring
call crlf
jmp continuebatting


moreovers :
cmp ecx, 12
je secondover
jb moreover1
jmp continuebatting

secondover :
call crlf
mov edx, OFFSET overtwo
call writestring
call crlf
jmp continuebatting

moreover1 :
cmp ecx, 6
je thirdover
jmp continuebatting


thirdover :
call crlf
mov edx, OFFSET overthree
call writestring
call crlf
jmp continuebatting


continuebatting :




cmp esi, 4
je noplayersleft1
jmp conti

noplayersleft1 :
jmp outofloop

conti :
mov eax, 5
ADD eax, 1
call RandomRange

cmp eax, 1
je onerun
jg morethenone

onerun :
mov al, 4
ADD team4playersscore[esi], al
ADD team4totalscore, al
ADD team4ballcounter[esi], 1
ADD team44counter[esi], 1
mov edx, OFFSET fourmsg
call writestring
call crlf
jmp endbattingloop

morethenone :
cmp eax, 2
je tworun
jg morethentwo

tworun :
mov al, 6
ADD team4playersscore[esi], al
ADD team4totalscore, al
ADD team46counter[esi], 1
ADD team4ballcounter[esi], 1
mov edx, OFFSET sixmsg
call writestring
call crlf
jmp endbattingloop

morethentwo :
cmp eax, 3
je threerun
jg morethenthree

threerun :
mov al, 1
ADD team4playersscore[esi], al
ADD team4totalscore, al
ADD team4ballcounter[esi], 1
INC extracounter
INC ecx
mov al, 9
call writechar
mov edx, OFFSET extramsg
call writestring
call crlf
jmp endbattingloop

morethenthree :
ADD esi, 1
mov edx, OFFSET outmsg
call writestring
call crlf

endbattingloop :

DEC ecx
jnz batingloop


outofloop :

COMMENT !---------------------------------- - TEAM 4 FINAL RESULT OF PLAYERS---------------------------- - !

call crlf
xor esi, esi
mov edx, OFFSET sashka
call writestring
call crlf
call crlf

mov edx, OFFSET scoreboard
call writestring
call crlf

mov edx, OFFSET playername
call writestring

mov al, 9
call writechar

mov edx, offset ballsplayedmsg
call writestring

mov al, 9
call writechar

mov edx, OFFSET foursmsg
call writestring

mov al, 9
call writechar

mov edx, offset sixesmsg
call writestring

mov al, 9
call writechar

mov edx, OFFSET playerscore
call writestring
call crlf

mov edx, OFFSET team4player1name
call writestring

mov al, 9
call writechar

mov al, team4ballcounter[0]
call writeint

mov al, 9
call writechar

mov al, team46counter[0]
call writeint

mov al, 9
call writechar

mov al, team46counter[0]
call writeint

mov al, 9
call writechar

mov al, team4playersscore[0]
call writeint
call crlf

mov edx, OFFSET team4player2name
call writestring

mov al, 9
call writechar

mov al, team4ballcounter[1]
call writeint

mov al, 9
call writechar

mov al, team46counter[1]
call writeint

mov al, 9
call writechar

mov al, team46counter[1]
call writeint

mov al, 9
call writechar

mov al, team4playersscore[1]
call writeint
call crlf

mov edx, OFFSET team4player3name
call writestring

mov al, 9
call writechar

mov al, team4ballcounter[2]
call writeint

mov al, 9
call writechar

mov al, team46counter[2]
call writeint

mov al, 9
call writechar

mov al, team46counter[2]
call writeint

mov al, 9
call writechar

mov al, team4playersscore[2]
call writeint
call crlf

mov edx, OFFSET team4player4name
call writestring

mov al, 9
call writechar

mov al, team4ballcounter[3]
call writeint

mov al, 9
call writechar

mov al, team46counter[3]
call writeint

mov al, 9
call writechar

mov al, team46counter[3]
call writeint

mov al, 9
call writechar

mov al, team4playersscore[3]
call writeint
call crlf
call crlf
mov edx, OFFSET extrasmsg
call writestring
mov al, extracounter
call writeint
call crlf


mov al, 9

call writechar
mov edx, OFFSET team4name
call writestring

mov edx, OFFSET playerscore
call writestring

mov al, team4totalscore
call writeint
call crlf

endteam4turn :

COMMENT !---------------------------------- - TEAM 4 BATTING ENDS---------------------------- - !

ret
team4batting ENDP




END main
