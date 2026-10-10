# Starší sketche v repozitáři

**Potvrzeno z checkoutu:** nalezeno 24 souborů `.ino`. Níže je inventura podle obsahu a názvů souborů. Funkčnost, zapojení ani kompatibilita všech sketchů nebyly testovány.

| Oblast | Sketche | Co je v kódu |
| --- | --- | --- |
| LED (3) | `test_blikani_dvou_diod`, `test_blikani_tri_diod`, `test_stmivani_diod` | Blikání a změna jasu LED. |
| Registr a segmentovka (6) | `test_posuvneho_ragistru`, `test_segmentovka`, `test_segmentovka_s_tlacitkem`, `test_segmentovka_s_tlacitkem_random`, `test_segmentovka_s_dvema_tlacitky`, `test_segmentovka_s_tremi_tlacitky` | Zápis přes posuvný registr, číslice a ovládání tlačítky. Poslední sketch používá knihovnu `libraries/MojeNastaveni`. |
| LED matice (5) | `srdce`, `matrix_baf`, `puvodni_animace`, `life`, `67` | Obrázky, animace a varianty Game of Life s `Arduino_LED_Matrix`. |
| Cloud a Wi-Fi (2) | `test_home`, `test_wifi_feb28a` | Příklady s `thingProperties.h`, cloudovými proměnnými a ovládáním LED či animace. |
| Zvuk (7) | `carvadele_mluvi`, `zvukznovu`, `_ZVUK/test_aktivni_bzucak_sos`, `_ZVUK/test_pasivni_bzucak`, `_ZVUK/test_zvuk`, `_ZVUK/test_zvuk_tranz_chaos`, `_ZVUK/zesilovac2_frekvence` | Bzučáky, zvuková data, DAC a pokusy se zesilovačem. Ve `_ZVUK` jsou i WAV soubory a převodní skripty. |
| Rozpracované (1) | `pokus` | Obsahuje testovací text, který není platný kód; nelze jej brát jako hotový sketch. |

Složka `test_home_` neobsahuje `.ino` a do počtu nepatří. Inventura zatím neurčuje, které pokusy budou součástí další verze R2D2.
