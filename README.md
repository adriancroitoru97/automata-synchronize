Adrian-Valeriu Croitoru | 332CA

1. Stari accesibile (accessible)
    Pentru aceasta cerinta, am folosit algoritmul clasic de BFS Pentru
    a parcurge starile automatului (care este asemeni unui graf).
    La final, vectorul `visited` va contine exact starile in care s-a
    ajuns in urma parcurgerii in latime.

2. Sincronizare (synchronize)
    La aceasta cerinta am folosit algoritmul DFS, astfel:
    Se pleaca de la setul de stari initiale. Se alege in continuare simbolul
    in urma caruia vor rezulta cele mai multe stari egale.
        Spre ex: initial avem starile 1,2,3,4
                 aplicam simbolul `0` pe ele => starile 2,2,4,2
                 aplicam simbolul `1` pe ele => starile 1,2,3,5
                 Se va alege in continuare simbolul `0`, intrucat
                 au rezultat deja 3 stari egale, ceea ce ne face sa credem
                 ca suntem mai aproape de rezultatul final (in eventualitatea
                 in care 2 ar fi stare finala)
    Se continua aceasta abrodare greedy in adancime pana se ajunge la
    rezultatul final, sincronizarea. Se retin pe fiecare path simbolurile
    folosite pana atunci,dar si succesiunea de stari prin care s-a ajuns acolo.
    La fiecare pas, se verifica sa nu ciclam (sa ajungem intr-o stare in care
    am mai fost deja).
    Se observa, intr-adevar, ca doua teste pica. Acest lucru este,
    cel mai probabil, datorat faptului ca verificarea ciclicitatii se face
    pe intreg setul de stari, si nu individual pe fiecare stare, insa timpul
    limitat de rezolvare a cerintei nu mi-a permis sa ma mai ocup si de
    aceasta problema.
