#include "Warlock.hpp"
#include "Dummy.hpp"
#include "Fwoosh.hpp"
#include "Fireball.hpp"
#include "Polymorph.hpp"
#include "BrickWall.hpp"
#include "TargetGenerator.hpp"
#include "SpellBook.hpp"

int main()
{
    std::cout << "=== Test Warlock Creation and Basic Functions ===" << std::endl;
    
    // Test création et destruction du Warlock
    Warlock richard("Richard", "Foo");
    richard.setTitle("the Magnificent");
    richard.introduce();
    
    std::cout << "\n=== Test Spell Learning and Launching ===" << std::endl;
    
    // Création des sorts
    Fwoosh* fwoosh = new Fwoosh();
    Fireball* fireball = new Fireball();
    Polymorph* polymorph = new Polymorph();
    
    // Apprentissage des sorts
    richard.learnSpell(fwoosh);
    richard.learnSpell(fireball);
    richard.learnSpell(polymorph);
    
    // Création des cibles
    Dummy dummy;
    BrickWall wall;
    
    std::cout << "\n=== Test Direct Spell Casting ===" << std::endl;
    
    // Test des sorts sur différentes cibles
    richard.launchSpell("Fwoosh", dummy);
    richard.launchSpell("Fireball", wall);
    richard.launchSpell("Polymorph", dummy);
    
    // Test sort inexistant
    richard.launchSpell("Lightning Bolt", dummy);
    
    std::cout << "\n=== Test TargetGenerator ===" << std::endl;
    
    // Test du générateur de cibles
    TargetGenerator tarGen;
    
    std::cout << "Tentative de créer une cible AVANT apprentissage :" << std::endl;
    ATarget* failedTarget = tarGen.createTarget("Target Practice Dummy");
    if (!failedTarget) {
        std::cout << "Échec : le générateur ne connaît pas encore ce type de cible" << std::endl;
    }
    
    std::cout << "\nApprentissage des types de cibles (comme des modèles) :" << std::endl;
    tarGen.learnTargetType(&dummy);  // On "enseigne" le type Dummy
    tarGen.learnTargetType(&wall);   // On "enseigne" le type BrickWall
    std::cout << "Types de cibles enseignés : Dummy et BrickWall" << std::endl;
    
    std::cout << "\nMaintenant on peut créer des cibles à la demande :" << std::endl;
    // Création de nouvelles cibles basées sur les modèles appris
    ATarget* newDummy = tarGen.createTarget("Target Practice Dummy");
    ATarget* newWall = tarGen.createTarget("Inconspicuous Red-brick Wall");
    ATarget* unknown = tarGen.createTarget("Unknown Target");
    
    if (newDummy) std::cout << "✓ Dummy créé avec succès" << std::endl;
    if (newWall) std::cout << "✓ BrickWall créé avec succès" << std::endl;
    if (!unknown) std::cout << "✗ Type inconnu : création échouée (normal)" << std::endl;
    
    std::cout << "\n=== Test Generated Targets ===" << std::endl;
    
    std::cout << "Test avec les cibles générées :" << std::endl;
    if (newDummy) {
        richard.launchSpell("Fwoosh", *newDummy);
        richard.launchSpell("Fireball", *newDummy);
    }
    
    if (newWall) {
        richard.launchSpell("Polymorph", *newWall);
        richard.launchSpell("Fireball", *newWall);
    }
    
    std::cout << "\nCréation de multiples cibles du même type :" << std::endl;
    ATarget* dummy1 = tarGen.createTarget("Target Practice Dummy");
    ATarget* dummy2 = tarGen.createTarget("Target Practice Dummy");
    ATarget* dummy3 = tarGen.createTarget("Target Practice Dummy");
    
    std::cout << "Créé 3 Dummy différents à partir du même modèle :" << std::endl;
    if (dummy1) richard.launchSpell("Fwoosh", *dummy1);
    if (dummy2) richard.launchSpell("Fireball", *dummy2);
    if (dummy3) richard.launchSpell("Polymorph", *dummy3);
    
    // Nettoyage des dummies supplémentaires
    delete dummy1;
    delete dummy2;
    delete dummy3;
    
    if (unknown) {
        std::cout << "This should not appear (unknown target created)" << std::endl;
    } else {
        std::cout << "Correctly failed to create unknown target type" << std::endl;
    }
    
    std::cout << "\n=== Test Spell Forgetting ===" << std::endl;
    
    // Test oubli de sorts
    richard.forgetSpell("Fwoosh");
    richard.launchSpell("Fwoosh", dummy); // Should fail
    richard.launchSpell("Fireball", dummy); // Should work
    
    // Oubli d'un sort inexistant
    richard.forgetSpell("Lightning Bolt");
    
    std::cout << "\n=== Test Clone Functionality ===" << std::endl;
    
    // Test du clonage
    ASpell* clonedFireball = fireball->clone();
    ATarget* clonedDummy = dummy.clone();
    
    if (clonedFireball && clonedDummy) {
        std::cout << "Cloned spell: " << clonedFireball->getName() << std::endl;
        std::cout << "Cloned target: " << clonedDummy->getType() << std::endl;
        
        // Test du sort cloné
        clonedFireball->launch(*clonedDummy);
    }
    
    std::cout << "\n=== Test Multiple Warlocks ===" << std::endl;
    
    {
        Warlock gandalf("Gandalf", "the Grey");
        gandalf.introduce();
        
        // Chaque Warlock a son propre SpellBook
        gandalf.launchSpell("Fireball", dummy); // Should fail - Gandalf doesn't know Fireball
        
        Polymorph* gandalf_polymorph = new Polymorph();
        gandalf.learnSpell(gandalf_polymorph);
        gandalf.launchSpell("Polymorph", dummy); // Should work
        
        // Gandalf sera détruit ici (fin de scope)
    }
    
    std::cout << "\n=== Cleanup ===" << std::endl;
    
    // Nettoyage mémoire
    if (newDummy) delete newDummy;
    if (newWall) delete newWall;
    if (clonedFireball) delete clonedFireball;
    if (clonedDummy) delete clonedDummy;
    
    std::cout << "\n=== End of Tests ===" << std::endl;
    
    // Richard sera détruit automatiquement à la fin du main
    return 0;
}