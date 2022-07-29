Solution of Attached problem file "COP-4338 SystemProgramming.pdf"

Tool used: Visual Studio 2019 Enterprise


#######################################################################

Problem

COP-4338SystemProgrammingProgrammingAssignment2:Pointers
FIU KnightFoundationSchoolofComp.&InfoSciences
In thisassignment,youwillwriteaprogramthatperformsencryption/decryptionusinga
verysimpletranspositiontechniqueinspiredbytheRailFenceCipher.Let'sseeanexample
to illustratehowitworks:
Assume thatwearegoingtoencryptthefollowingplain-textmessagebeforesendingit
out toprovidesomelevelofsecurity:
The warstartsatsevenAM.
Bring waterandcannedfood.
Don't attackfromWest.
Playmusicwhenyouarrive.
The rststepistoseparatethewordsineachsentencebywhitespacecharacterand
place allthewordsinatablelikethis:
0 1 2 3 4 5
the war starts at seven am
bring water and canned food
don't attack from west
play music when you arrive
As yousee,everycolumnofthistableislabeledwithanon-negativeinteger.Then,we
use agivenpermutationofthecolumnlabelslike(3; 5; 2; 1; 0; 4) toobtaintheencrypted
text (calledthecipher-text).Thegivenpermutationiscalled the encryptionkey. Toobtain
the cipher-text,weneedtoiteratethroughcolumnsofthistableintheorderspeciedby
the key.Foreachcolumn,welistthewordsinthecolumnfromtoptobottom.Sincethe
numberofwordsineachrowmaybedierent,youmayndsomemissingcellsinacolumn.
In suchcases,weusethellerword\null"(e.g.thewordsincolumn4are:\seven,food,
null,arrive").Therefore,thecipher-textinthisexamplewillbe:
at cannedwestyouamnullnullnullstartsandfromwhenwar
waterattackmusicthebringdon'tplaysevenfoodnullarrive
1
The recipientofthismessagecandecrypttheabovecipher-texteasilyaslongasthey
knowwhatthekeyis(inthisexample,(3; 5; 2; 1; 0; 4)). Herearethestepsfordecryption
and obtainingplain-textfromcipher-text:
1. Countthenumberwords n in thecipher-text(24wordsinthisexample).
2. Dividethenumberofwords(n = 24)bythelengthofgivenkey(k = 6): n=k = 4.
3. Drawatablewith n=k rowsand k columns
4. Placewordsinthecolumnsofdrawntableusingtheordergivenbythekey.
5. Extracteachsentencefromeachrowofthetableafterremovingtheller(null)words.
1 ProgramInputCommands
There arethreevalidcommandsforyourprogram:
 encrypt (a0; a1; :::;ak􀀀1)  - PLAINTEXT Ctrl D: encryptsthegivenplain-textusing
the givenkeywhichisapermutationoftherst k non-negativeintegers.Theplain-
text startswithanewlinecharacterandendswithanEOFcharacterwhichisentered
via keyboardusingCtrl+D.Thiscommandprintstheencryptedtextonthescreen.
Forthesakeofsimplicity,assumethat:
{ Plain-text ismadeoroneormoresentences(at-most5000sentences).
{ Everysentenceendswithadot(.).
{ Twoconsecutivesentencesareseparatedbyasinglenewlinecharacter.
{ Eachsentenceismadeofat-most100wordsseparatedbywhite-space.
{ Eachwordinasentenceismadeofonlylowercasealphabeticallettersoran
apostrophe.Lengthofeachwordisat-most24characters.
{ No punctuationmarksareusedintheplain-textexceptapostropheanddot.
 decrypt (a0; a1; :::;ak􀀀1)  - CIPHERTEXT Ctrl D: decryptsthegivencipher-text
using thegivenkeywhichisapermutationoftherst k non-negativeintegers.The
cipher-text startswithanewlinecharacterandendswithanEOFcharacterwhichis
enteredviakeyboardusingCtrl+D.Thiscommandprintsthedecryptedtextonthe
screen. Forthesakeofsimplicity,assumethatthecipher-textcontainsnonewline
character.
 quit: endstheprogram.
2 Submissions
Youneedtosubmita .zip le compressingthefollowings:
 all of.cand.hlesoftheprogram,
 Makelewhichorganizesthecompilationprocessofyourprogram.


Enjoy
