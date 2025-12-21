# C++ / Qt Object-Oriented Combat Game

Dit project is een turn-based combat game geschreven in modern C++ en opgezet als een **Qt-project**. Het doel van dit project is het aantonen van correcte en nuttige object-oriented programming principes (abstraction, encapsulation, inheritance, polymorphism en composition), gecombineerd met moderne C++-features en een **volledig reproduceerbare build vanaf een schone computer**.

Het spel bestaat uit een Hero die het opneemt tegen één of meerdere Enemies. De combat verloopt in rondes waarbij aanvallen, poison, healing, leveling, weapon drops en enemy summoning dynamisch plaatsvinden. Het spel eindigt wanneer de Hero sterft of wanneer alle Enemies verslagen zijn. Na afloop wordt automatisch een `save.txt`-bestand aangemaakt met de huidige game state.

Het project maakt gebruik van moderne C++-technieken zoals smart pointers (`std::shared_ptr`), templates, lambda functies, STL containers, file-I/O, `unsigned char` voor geheugen-efficiëntie, `nullptr`, const references en dynamisch geheugenbeheer met `new` en `delete`. Alle code bevindt zich binnen een zelfgemaakte namespace. Het project compileert correct, crasht niet en werkt volledig zoals bedoeld.

---

BUILD MANUAL – VANAF EEN SCHONE PC (QT)

Dit project is **bedoeld om gebouwd te worden met Qt**. Er is bewust gekozen voor Qt tooling. Er is geen alternatieve build-methode nodig.

1. Vereisten:
   - Een schone computer (Windows, Linux of macOS)
   - Git
   - Qt 6.x (of Qt 5.15+) inclusief Qt Creator  
     (te installeren via de officiële Qt Online Installer)

2. Qt installeren:
   - Ga naar [https://www.qt.io/download](https://www.qt.io/development/download)
   - Download en installeer Qt via de Qt Online Installer
   - Selecteer tijdens installatie:
     - Qt 6.10 for desktop development 
   - Voltooi de installatie met standaardinstellingen

3. Repository clonen:
   - Open een terminal of Git Bash en voer uit:
   - cd <PROJECT_FOLDER>
   - git clone https://github.com/feefranssen/Project-cpp
   
5. Project openen in Qt Creator:
   - Start Qt Creator
   - Kies: File → Open File or Project
   - Open het `spel` bestand 
   - Qt Creator detecteert automatisch dat dit een Qt-project is

6. Project configureren:
   - Kies een Desktop Kit 
   - Laat alle standaardinstellingen ongewijzigd
   - Klik op “Configure Project”

7. Compileren:
   - Klik op de “Build” knop
   - Of gebruik sneltoets: Ctrl + B

8. Uitvoeren:
   - Klik op de “Run” knop
   - Of gebruik sneltoets: Ctrl + R

9. Verwacht resultaat:
   - Het bestand `save.txt` bevindt zich in de build-map van het project  
     (bijvoorbeeld: `build-<projectnaam>-Desktop_xxx/`)
     

Dit project kan volledig vanaf nul worden gebouwd en uitgevoerd op een schone computer door enkel Qt te installeren en bovenstaande stappen exact te volgen. Er zijn geen extra configuraties, externe libraries of handmatige aanpassingen nodig.


## Test-driven development (geschreven testplan)

Voor de implementatie van de spel­logica zijn onderstaande testgevallen opgesteld om het correcte gedrag van de belangrijkste onderdelen te verifiëren.  
Deze testgevallen zijn gebruikt voor manuele verificatie tijdens de ontwikkeling.

### Testgevallen

1. **Character ontvangt schade**
- Gegeven een character met 50 HP  
- Wanneer het character 20 schade ontvangt  
- Dan moet de HP 30 zijn  

2. **Character kan geen negatieve HP hebben**
- Gegeven een character met 10 HP  
- Wanneer het character 50 schade ontvangt  
- Dan moet de HP 0 zijn  

3. **Hero geneest correct**
- Gegeven een hero met 80 HP  
- Wanneer de hero 10 HP geneest  
- Dan moet de HP 90 zijn  

4. **Enemy aanval verlaagt hero HP**
- Gegeven een hero en een enemy  
- Wanneer de enemy de hero aanvalt  
- Dan moet de HP van de hero verminderen  

5. **Poison schade wordt correct toegepast**
- Gegeven een vergiftigde hero  
- Wanneer twee rondes voorbijgaan  
- Dan wordt poison schade twee keer toegepast en stopt daarna  

> **Opmerking:** Het testplan is opgesteld om alle kernfunctionaliteit van het spel systematisch te controleren. Het kan handmatig uitgevoerd worden om te verifiëren dat alle features correct werken.

---
