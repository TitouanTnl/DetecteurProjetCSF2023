Ce projet est réalisé dans le cadre du module Communication Sans Fil en Licence 1 à l’Université Côte D'Azur

# Principe du projet
Le capteur a pour premiere utilisation de detecter la fumée et les gaz nocifs tels que : le GPL, le propane, l'isobutane, le méthane...
<br/>Ainsi il nous previens lorsqu'il y a de la fumée dans la piece.
<br/>Il a une autre fonction : il detecte si quelqu'un entre dans la piece, il peut ainsi nous prevenir s'il y a un intrusion ou simplement allumer la lumiere pendant un certain temps afin de ne pas avoir d'interrupteur et d'economiser de l'energie.

# Materiel necessaire:
- Carte UCA
- Breadboard
- Fils de connection
- Capteur à ultrason : HC-SR04
- Capteur de gaz : MQ-2
- Un ordinateur avec Arduino IDE

# Branchements
## Capteur à ultrason
Il y a 4 fils a brancher pour ce capteur :
- VCC -> V_IN
- GND -> GND
- Trig -> A1
- Echo -> A2

## Capteur de fumée
Il y a 3 fils pour ce capteur :
- VCC -> V_IN
- GND -> GND
- DO -> A3

<br/>
<br/>
![](https://github.com/TitouanTnl/DetecteurProjetCSF2023/blob/main/Doc/IMG.jpg)
