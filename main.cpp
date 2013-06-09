#include <QApplication>
#include <QDebug>
#include <QSettings>
#include "mainwindow.h"

/*! \mainpage Notability Projet LO21 - [Siqi Liu] & [Marion Depuydt]
 *
 * \section Introduction
 *
 *
 *
* \subsection Gestion Gestion des Tags:
 * Pour gérer les tags, nous avons choisi d'implémenter une classe Tag qui a comme attribut un QSet<Note*>. Cela permet d'avoir accès à partir du tag à toutes les notes qui y sont associées. Nous pouvons dans cette classe avoir accès et changer le nom du tag. Mais aussi d'insérer et de supprimer une note du QSet.
*
* La classe TagManager quant à elle permet de contrôler l'accès aux tags ainsi dans n'importe quelle classe si on veut rajouter un tag ou un tag à une note, nous sommes obligé de passer par le TagManager. Nous avons défini la classe TagManager étant un singleton ainsi elle ne peut être instancier qu'une seule fois.
*
* Quant à l'interface, nous avons choisi de présenter les tags sous la forme d'une liste de checkBox. Un tag peut être créer à l'aide du bouton + sans avoir de liens avec une note. Par contre, il est interdit de créer 2 notes de même noms, cela n'aurait pas de sens. En effet, si 2 tags ont les même noms comment différencier les notes qui s'y référent.
*
* Nous pouvons changer son nom directement en double cliquant dessus. Quand un tag est selectionné, nous pouvons le supprimer à l'aide du bouton -.
*
* Dans l'éditor, pour chaque note nous trouvons un bouton Tag qui permet d'associer la note éditée à un des tags existants.
*
* Par défaut tous les tags sont cochés, cela permet de voir l'ensemble des notes à l'ouverture de l'application dans le TreeView. Quand on décoche un tag, cela enlève de la liste des notes, toutes les notes qui n'y sont pas associées. Cela permet de filtrer les notes avec des mots clés.

* Afin d'améliorer la recherche d'un documet, nous avons décidé d'implémenter aussi une recherche par nom d'article dans le TextEdit Search for notes.
*
* Pour finir pour que nous puissions revenir sur nos actions, nous avons mis en place la classe RemoveCurrentTagCmd qui hérite de QUndoCommand et permet de garder en mémoire les actions effectuées à partir des tags et met en place la possibilité de faire undo redo à notre convenance sur toutes les actions effectuées depuis l'exécution de l'application. De plus, History permet d'afficher la boite de dialogue de toutes actions effectuées et de directement choisir à quel point nous voulons revenir.
 *
 *
 * \subsection Améliorations
 *Pour améliorer ce logiciel de prise de notes, nous pourrions :
 *-remplacer les parcours recursifs par des iterateurs profondeur d'abord qu'on a implemente dans Document.h
 *-ajouter le undo, redo pour toutes les actions du programme
 *-ajouter un correcteur orthographique
 *-modifier la typographie
 *-avoir une reconnaissance vocale
 *
 * \section UML
 * \image html ../UMLf.png
 */

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    QCoreApplication::setOrganizationName("Notability");
    QCoreApplication::setOrganizationDomain("notability.fr");
    QCoreApplication::setApplicationName("Notability");

    MainWindow *editor = MainWindow::getInstance();
    editor->show();

    return a.exec();
}
