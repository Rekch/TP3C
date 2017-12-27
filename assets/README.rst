Ressources graphiques
~~~~~~~~~~~~~~~~~~~~~

Ce dépôt contient les fichiers utilisés pour produire les feuilles de sprites
nécessaires à la réalisation du travail pratique 3 du cours INF3135
Construction et maintenance de logiciels, à la session d'automne 2017, à
l'Université du Québec à Montréal.

Fichiers Blender
================

Les fichiers avec l'extension ``.blend`` sont des fichiers qui peuvent être
ouverts avec le logiciel libre `Blender <https://www.blender.org/>`__. Il n'est
pas nécessaire de manipuler ces fichiers pour compléter le travail pratique,
mais je souhaitais tout de même partager les sources pour ceux qui souhaitent
comprendre comment cela fonctionne.

Feuilles de sprites
===================

Une `feuille de sprites
<https://en.wikipedia.org/wiki/Sprite_(computer_graphics)>`__ est une image qui
contient plusieurs petites images organisées de façon logique.  Il y a
actuellement deux feuilles de sprites dans ce dossier:

- `character.png`, qui contient 5 lignes de 32 images permettant d'animer un
  personnage. Chaque ligne décrit une action spécifique du personnage. Dans
  l'ordre, les actions sont *marcher vers la droite*, *marcher vers la gauche*,
  *être inactif*, *sauter verticalement*, *sauter vers la droite* et *sauter
  vers la gauche*.

  .. image:: character.gif
     :width: 128px
     :alt: Un personnage animé effectuant 5 actions

- `donut.png`, qui contient 1 ligne de 32 images permettant d'animer un beigne.
  Ce beigne a donc une seule action, qui consiste à tourner sur lui-même.

  .. image:: donut.gif
     :width: 128px
     :alt: Un beigne tournant sur lui-même

License
=======

Tout le contenu de ce projet est sous `license GPLv3
<https://www.gnu.org/licenses/gpl-3.0.en.html>`__.  Toutes les ressources
graphiques sont sous `license Creative Commons 3.0
<https://creativecommons.org/licenses/by-nc/3.0/us/deed.en_US>`__
