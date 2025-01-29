# Makefile du projet "Bataille navale" A PLACER dans le répertoire /ws du projet VSCode

# Chaque classe du projet doit être testée séparément.
# Il y aura donc un lanceur (main) par classe à tester.

# Ce makefile doit permettre de faire :
#	- la compilation du lanceur associé à chaque classe à tester
#	- la compilation du projet final (c-à-d main.cpp)

# Déclaration de quelques variables utiles au makefile
GPP = g++ -Wall
SRC = ./src
BIN = ./bin

# La cible "deleteAll" est exécutée en tapant la commande "make deleteAll"
deleteAll :
	@# Précéder chaque commande d'une TABULATION
	@echo suppression du contenu du répertoire ./bin
	rm -f $(BIN)/*.o $(BIN)/*.bin

# Test de la classe CBateau
# Compilation du lanceur testCBateau, pour cela (l'ordre de compilation est important en C++) :
#	- supprimer le contenu du répertoire "./bin" et
#	- d'abord compiler CBateau
#	- ensuite compiler testCBateau

# La cible "testCBateau" est exécutée en la déclarant correctement sous VSCode
testCBateau : deleteAll compilCBateau compilTestCBateau

# La cible "compilCBateau" est exécutée en la déclarant correctement sous VSCode
compilCBateau :
	@# Précéder chaque commande d'une TABULATION
	@echo Compilation CBateau
	$(GPP)	$(SRC)/CBateau.cpp -o	$(BIN)/CBateau.o -c

# La cible "compilTestCBateau" est exécutée en la déclarant correctement sous VSCode
compilTestCBateau :
	@# Précéder chaque commande d'une TABULATION
	@echo Compilation testCBateau
	$(GPP)	$(SRC)/testCBateau.cpp	$(BIN)/CBateau.o -o	$(BIN)/testCBateau.bin


# Test de la classe CArmada
# Compilation du lanceur testCArmada, pour cela (l'ordre de compilation est important en C++) :
#	- supprimer le contenu du répertoire "./bin" et
#	- d'abord compiler CArmada
#	- ensuite compiler testCArmda

# La cible "testCArmada" est exécutée en la déclarant correctement sous VSCode
testCArmada : deleteAll compilCArmada compilTestCArmada

# La cible "compilCArmada" est exécutée en la déclarant correctement sous VSCode
compilCArmada :
	@# Précéder chaque commande d'une TABULATION
	@echo Compilation CArmada
	$(GPP)	$(SRC)/CArmada.cpp -o	$(BIN)/CArmada.o -c

# La cible "compilTestCArmada" est exécutée en la déclarant correctement sous VSCode
compilTestCArmada :
	@# Précéder chaque commande d'une TABULATION
	@echo Compilation testCArmada
	$(GPP)	$(SRC)/testCArmada.cpp	$(BIN)/CArmada.o	$(BIN)/CBateau.o -o	$(BIN)/testCArmada.bin

# Test de la classe CGui
# Compilation du lanceur testCGui, pour cela (l'ordre de compilation est important en C++) :
#	- supprimer le contenu du répertoire "./bin" et
#	- d'abord compiler CGui
#	- ensuite compiler testCGui

# La cible "testCGui" est exécutée en la déclarant correctement sous VSCode
testCGui : deleteAll compilCGui compilTestCGui

# La cible "compilCGui" est exécutée en la déclarant correctement sous VSCode
compilCGui :
	@# Précéder chaque commande d'une TABULATION
	@echo Compilation CGui
	$(GPP)	$(SRC)/CGui.cpp -o	$(BIN)/CGui.o -c

# La cible "compilTestCGui" est exécutée en la déclarant correctement sous VSCode
compilTestCGui :
	@# Précéder chaque commande d'une TABULATION
	@echo Compilation testCGui
	$(GPP)	$(SRC)/testCGui.cpp	$(BIN)/CGui.o	$(BIN)/CArmada.o	$(BIN)/CCoups.o	$(BIN)/CBateau.o -o	$(BIN)/testCGui.bin

# CCoups
compilCCoups :
	@echo Compilation CCoups
	$(GPP)	$(SRC)/CCoups.cpp -o	$(BIN)/CCoups.o -c

# CSocket
compilCSocket :
	@echo Compilation CSocket
	$(GPP)	$(SRC)/CSocket.cpp -o	$(BIN)/CSocket.o -c

# CClientSocket
compilCClientSocket :
	@echo Compilation CClientSocket
	$(GPP)	$(SRC)/CClientSocket.cpp -o	$(BIN)/CClientSocket.o -c

# CServerSocket
compilCServerSocket :
	@echo Compilation CServerSocket
	$(GPP)	$(SRC)/CServerSocket.cpp -o	$(BIN)/CServerSocket.o -c

# CJoueur
compilCJoueur :
	@echo Compilation CJoueur
	$(GPP)	$(SRC)/CJoueur.cpp -o	$(BIN)/CJoueur.o -c

# CJoueurCli
compilCJoueurCli :
	@echo Compilation CJoueurCli
	$(GPP)	$(SRC)/CJoueurCli.cpp -o	$(BIN)/CJoueurCli.o -c

# CJoueurServ
compilCJoueurServ :
	@echo Compilation CJoueurServ
	$(GPP)	$(SRC)/CJoueurServ.cpp -o	$(BIN)/CJoueurServ.o -c


# ICI, la cible de compilation finale pour obtenir main.bin
# A executer A LA FIN du projet en s'assurant que toutes les classes du projet compilent et s'exécutent sans erreurs !
# La cible "lanceurFinal"
lanceurFinal : deleteAll compilCBateau compilCArmada compilCCoups compilCGui compilCSocket compilCClientSocket compilCServerSocket compilCJoueur compilCJoueurCli compilCJoueurServ
	@echo Compilation lanceurFinal
	$(GPP)	$(SRC)/main.cpp	$(BIN)/CBateau.o	$(BIN)/CArmada.o	$(BIN)/CCoups.o	$(BIN)/CGui.o	$(BIN)/CSocket.o	$(BIN)/CClientSocket.o	$(BIN)/CServerSocket.o	$(BIN)/CJoueur.o	$(BIN)/CJoueurCli.o	$(BIN)/CJoueurServ.o -o	$(BIN)/main.bin


