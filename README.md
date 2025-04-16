# 🚢 Bataille Navale (C++)

Jeu de bataille navale en réseau local, en **mode client-serveur**, codé en **C++**.  
Chaque joueur utilise un terminal distinct : l'un en tant que **serveur**, l'autre en **client**.

---

## 📦 Dépendances

- C++
- Sockets réseau (standard C++/POSIX)

---

## ⚙️ Fonctionnement

1. Lancez deux terminaux :
   - Un pour le **serveur**
   - Un pour le **client**
2. Le **serveur démarre** et attend la connexion du client
3. Chaque joueur positionne ses bateaux
4. Le jeu commence, les deux joueurs tirent à tour de rôle
5. Le premier à **couler toute la flotte ennemie** gagne 🎯

---

## 💡 Détails techniques

- L'interface graphique (`CGui`) est en mode terminal (affichage texte)
- Les échanges se font via sockets TCP/IP locales
- Le serveur envoie au client l’état initial du jeu via le fichier `flotille.txt`
- La logique de jeu repose sur les classes suivantes :
  - `CJoueurServ`, `CJoueurCli` : communication et gestion des tours
  - `CArmada` : définition et gestion de la flotte
  - `CCoups` : stockage et affichage des tirs
  - `CGui` : affichage et interactions

---

## 📁 Structure 

```
📦 bataille_navale/
 ┣ CJoueurServ.cpp / .h
 ┣ CJoueurCli.cpp / .h
 ┣ CArmada.cpp / .h
 ┣ CGui.cpp / .h
 ┣ main.cpp
 ┣ flotille.txt
```

---

## 📚 Documentation

Le code est commenté et organisé selon une structure classique C++.  
La documentation peut être consultée dans les fichiers `.h`.

---

## 👨‍💻 Auteur

Lucas Gelgon  
