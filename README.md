# C-Pattern-Matching

### Introduction

Le projet porte sur la recherche de motifs, ou patterns, (séquence de lettres correspondant à une expression régulière) dans une chaîne de caractères formée à partir d'un alphabet de 4 lettres. L'alphabet est constitué des 3 premières consonnes et de la première voyelle du nom de famille de l'étudiant. Si nécessaire, une ou plusieurs consonnes du prénom peuvent être utilisées.

_Exemples :_ 

| Dupont       | dptu |
| Roy Thomas   | rtho |
| Meyer Pierre | mrpe |


### Principes 

Voyons d'abord quelques principes sur la recherche par motifs avec les expressions rationnelles.

Pour indiquer un motif, il faut utiliser une notation qui puisse être traitée par un ordinateur. Cette notation, ou langage, est la syntaxe des expressions rationnelles.

Le langage des expressions rationnelles est formé de symboles et d'opérateurs. Les symboles sont les caractères du motif. Pour décrire les relations entre ceux-ci, on utilise les opérateurs suivants (donnés dans l'ordre des priorités décroissantes) :

Fermeture : une chaîne de symboles égaux de longueur variable ou un symbole optionnel (c'est le coeur même de la recherche par motifs).
Concaténation : Si deux symboles se suivent dans le motif, les caractères correspondants doivent se suivre aussi dans le texte.
Alternative : L'un des symboles de l'alternative doit apparaître dans le texte dans lequel le motif est recherché.
En plus de ces opérateurs associatifs à gauche, on peut utiliser des parenthèses pour modifier les priorités des opérations.

Dans beaucoup d'implantations des expressions rationnelles, les opérateurs de fermeture sont :

l'astérisque (*), qui signifie une répétition de 0 à n occurences d'un symbole ;
le plus (+), qui signifie une répétition de 1 à n occurences d'un symbole ;
le point d'interrogation (?), qui signifie une éventuelle occurrence d'un symbole.

_Exemples :_

A* correspond à une chaîne vide, à « A », « AA », « AAA », etc.
A+ correspond à « A », « AA », « AAA », etc.
A? correspond à une chaîne vide ou à « A ».
Pour indiquer une concaténation, on n'a pas besoin d'utiliser d'opérateur particulier. Une chaîne formée de tous les autres symboles est une concaténation. Par exemple, ABC correspond à « ABC ».

Une alternative est décrite avec un | entre les deux expressions rationnelles possibles. A\B correspond à « A » ou à « B ».

Dans les implantations étendues des expressions rationnelles, on utilise d'autres opérateurs pour décrire plus efficacement les motifs complexes. Cet article ne sera qu'une petite introduction aux possibilités syntaxiques et non une référence détaillée.

### Installation 

Cloner le lien github avec <https://github.com/azetoy/C-Pattern-Matching>

Ou télécharger le dossier

Executez la commande ``make`` pour commencer et ensuite faire ``./PatternMatching``

### Fabriqué avec

* [Code Visual Studio](https://code.visualstudio.com/) - Editeur de textes 

### Auteurs

* **Zineddine Berrichi** _alias_ [@azetoy](https://github.com/azetoy)

Lisez la liste des [contributeurs](https://github.com/azetoy/C-Pattern-Matching/contributors) pour voir qui à aidé au projet !
