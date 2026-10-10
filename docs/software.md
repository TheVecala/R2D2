# Software a možnosti práce

| Nástroj | Úloha v projektu | Stav |
| --- | --- | --- |
| Arduino IDE 2 | Otevření, kompilace a nahrání existujících `.ino` sketchů. | Vhodný výchozí nástroj; konkrétní instalaci a verzi zde neověřujeme. |
| Arduino Cloud | Cloudové proměnné, zařízení a webové rozhraní; v repozitáři jsou příklady `test_home` a `test_wifi_feb28a`. | Kód existuje, aktuální účet a připojené zařízení nejsou ověřeny. |
| Arduino Cloud API | Možná integrace s cloudovými daty a správou přes REST API/SDK. | Možnost do budoucna; v repozitáři není ověřená vlastní integrace. |
| Arduino CLI | Příkazová kompilace sketchů a nahrávání na připojenou desku. | Volitelná pomůcka pro místní práci a automatizaci. |
| MicroPython | Alternativní způsob programování podporovaných desek v Pythonu. | Není náhradou existujících `.ino`; podporu konkrétní desky je nutné ověřit před volbou této cesty. |

**Pozor na názvy:** Arduino CLI pro sketche a Arduino Cloud CLI pro správu Cloudu jsou různé nástroje. Samotný vzdálený přístup ke Cloudu také neznamená, že lze bez dalšího nastavení nahrát program do desky ležící doma.

**Doma:** IDE 2 použít pro nahrání a zkoušky se zapojením. **Mimo domov:** upravovat kód a dokumentaci, případně kompilovat pro známou desku; cloudové funkce zkoušet jen u předem nastaveného a dostupného zařízení.

Oficiální přehledy: [Arduino IDE 2](https://docs.arduino.cc/software/ide/), [Arduino Cloud a API](https://docs.arduino.cc/arduino-cloud/), [Arduino CLI](https://docs.arduino.cc/arduino-cli/getting-started/), [MicroPython](https://docs.arduino.cc/micropython/).
