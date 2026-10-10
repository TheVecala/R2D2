# Arduino poznámky

## Potvrzeno v existujícím kódu

- Sketche s LED maticí používají `Arduino_LED_Matrix`; soubory `life` a `67` pracují s Game of Life.
- Pokusy se segmentovkou posílají data pomocí `shiftOut`; v několika sketchech jsou pro registr použity piny 11, 12 a 13. Varianty s tlačítky používají další vstupní piny.
- `test_segmentovka` má v komentáři mapu číslic pro společnou katodu. Skutečný typ displeje ještě není ověřen.
- Zvukové pokusy zahrnují DAC na A0, `analogWave`, bzučáky a vzorkovaná data. Některé komentáře a knihovny míří na UNO R4.
- Cloudové pokusy mají `thingProperties.h`; `test_home` odkazuje i na `arduino_secrets.h`. Hodnoty přístupových údajů zde nezapisovat.

## Postup při návratu ke sketchi

1. Zapsat desku, použité knihovny a očekávané zapojení.
2. V IDE 2 vybrat správnou desku; před nahráním zkontrolovat port a kompilaci.
3. S připojeným hardwarem ověřit výsledek a případné odchylky zaznamenat do [poznámek](poznamky.md).

Kompilace ověřuje sestavení programu pro zvolenou desku. Sama nepotvrzuje, že je zapojení správné nebo že zařízení funguje podle očekávání.
