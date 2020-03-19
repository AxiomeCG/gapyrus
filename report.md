# Introduction
Ce rapport va traiter de l'utilisation de l'algèbre géométrique pour la construction de squelettes topologiques de formes 3D.

Voici un exemple de squelettisation obtenue avec des techniques classiques:
![Squelettisation d'un mesh de cheval - https://doc.cgal.org/latest/Surface_mesh_skeletonization](https://doc.cgal.org/latest/Surface_mesh_skeletonization/main_image_suggestion.png)

J'ai eu l'idée de ce sujet en suivant le cours de Géométrie discrète du semestre 1. Nous avons vu le principe d'axe médian et ses différentes définitions (feu d'un champ, grossissement de boules maximales...) et j'ai voulu explorer ce que cela pourrait donner en algèbre géométrique avec une métrique C3Ga.

## Exposition du problème

Il existe différentes définitions du squelette topologique. Pour certains auteurs, la notion de squelette est interchangeable avec la notion d'axe médian. D'autres font la séparation entre les deux notions. Pour ce document les deux termes seront équivalents. En effet, la base de mon travail réside dans la recherche de l'axe médian, que j'appelle le plus souvent squelette.
De la même manière, certains auteurs rapprochent l'usage du terme "Amincissement" pour la squelettisation et d'autres auteurs en font deux notions différentes. On parlera ici de la même manière, de squelettisation ou d'amincissement qui désigneront la même chose dans le rapport.

Voici les différentes définitions sur lesquels je me suis appuyé pour effectuer l'exploration :

### Points d'extinction du modèle de propagation du feu.

Prenons le cas 2D pour simplifier la définition. 
Le squelette est construit à partir d'un modèle de propagation de feu. Imaginons un champ d'herbe de la forme de notre forme 2D. On allume un feu en chaque bord. Le squelette est constitué de tous les points d'extinction du feu. 

![Démonstration du feu de champ](./images/grassfire.png)
Sur ce schéma, la ligne grasse représente le squelette résultant d'un rectangle. La ligne en pointillés représente le front de flammes qui progresse. Quand deux fronts de flammes se rejoignent il s'agit d'un point d'extinction.

### Centres de boules maximales/disques maximaux

En 2D nous utilisons des disques mais la méthode reste la même qu'en 3D où les disques sont des boules.

Une boule $B$ est dite maximale dans un ensemble $\Omega$ si elle est contenue dans $\Omega$ et que qu'aucune autre boule $B'$ de $\Omega$ ne contient cette boule. En d'autres termes, toute autre boule $B'$ qui contient $B$ doit nécessairement ne plus être contenue dans l'objet $\Omega$.

Le centre de chaque boule maximale forme les points de notre squelette.

![Squelette construit à partir de disques maximaux](https://d3i71xaburhd42.cloudfront.net/cfbbe1f7aeda6ad4d112b391579a2cf16dce95ff/3-Figure1-1.png)

### Centre de boules bitangentes/disques bitangents

C'est une définition assez proche de la précédente. En effet lorsque qu'une boule est maximale elle touche l'objet en au moins 2 points. Le grossissement d'une boule jusqu'à ce qu'elle touche l'objet peut alors être utilisé pour définir un squelette. Ainsi, en récupérant le centre de chaque boule bitangente (ou plus que bitangente), on obtient l'axe médian. 

C'est cette définition assez naturelle dans le cadre de l'algèbre géométrique que nous allons utiliser.

## Façon conventionnelle de résoudre le problème

# Analyse algorithmique choisie du problème

# Résultats obtenus

# Limites

# Extensions possibles

# Conclusion
