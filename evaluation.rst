Correction du TP3
~~~~~~~~~~~~~~~~~

Grille de points
================

+--------------------+-----------------------------------------------+---------+---------+
| Tâche              | Critères                                      | Note    | Sur     |
+====================+===============================================+=========+=========+
|                    | Gestion des états du jeu et du personnage     | 30      | 30      |
|                    +-----------------------------------------------+---------+---------+
|                    | Gestion des feuilles de sprites               | 20      | 20      |
|                    +-----------------------------------------------+---------+---------+
| Fonctionnabilité   | Gestion de la physique                        | 27      | 30      |
|                    +-----------------------------------------------+---------+---------+
|                    | Détection des collisions                      | 18      | 20      |
|                    +-----------------------------------------------+---------+---------+
|                    | Interaction avec l'environnement              | 20      | 20      |
+--------------------+-----------------------------------------------+---------+---------+
|                    | Compilation simple (``Makefile``)             | 10      | 10      |
| Distribution       +-----------------------------------------------+---------+---------+
|                    | Documentation du fonctionnement               | 25      | 30      |
+--------------------+-----------------------------------------------+---------+---------+
|                    | - Utilisation correcte de Git                 |         |         |
|                    | - Séparation claire des tâches                |         |         |
| Gestion du projet  | - Utilisation des branches                    | 30      | 40      |
|                    | - Utilisation de requêtes d'intégration       |         |         |
|                    | - Automatisation de la compilation            |         |         |
+--------------------+-----------------------------------------------+---------+---------+
| **Total**                                                          | **180** | **200** |
+--------------------+-----------------------------------------------+---------+---------+

Commentaires
============

- Très bon travail de façon générale. Le jeu est fonctionnel.
- Le personnage est bien animé. Le saut est un peu court, ce qui rend le jeu un
  peu inintéressant (ça n'aurait pas été difficile de le faire sauter plus
  haut). Aussi, il aurait préférable de créer un niveau de départ plus
  intéressant, j'ai dû le faire moi-même manuellement pour m'assurer que
  c'était correctement implémenté.
- Les feuilles de sprites sont bien gérées.
- La physique est correcte aussi (faire des sauts plus élevés).
- Petit bogue au niveau des collisions (on apparaît subitement sur une
  plateforme si on saute dessus, même si ce n'est pas assez haut).
- Bonne gestion de l'environnement.
- Le ``Makefile`` gère bien la compilation. Par contre, il semble y avoir des
  arguments inutiles dans les commandes d'édition des liens, ce qui affiche des
  avertissements.
- Le contenu du fichier ``README`` est adéquat. Cependant, le format Markdown
  n'est pas bien exploité. Il y a aussi plusieurs fautes de frappe et
  d'orthographe.
- L'utilisation de Git est correcte, mais pourrait être mieux. Les messages
  sont relativement descriptifs. Cependant, ils sont massifs. Il aurait fallu
  davantage diviser le travail en petits *commits* et en branches.
- La division des tâches est minimaliste.
