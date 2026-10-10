# R2D2 – pracovní dokumentace

R2D2 je pracovní název zvolený jen kvůli fonetické podobnosti se slovem **Arduino**. Název sám o sobě neznamená plán postavit robota.

## Co je ověřeno

- Repozitář obsahuje starší Arduino sketche, pomocné knihovny, zvuková data a fotografie seznamů součástek.
- Přehled 24 souborů `.ino` je v [projekty.md](projekty.md). Jde o inventuru kódu, nikoli o seznam hotových a funkčních projektů.
- Majitel potvrdil, že součástky na třech fotografiích přidaných v commitu `b1418559` má. Aktuální počty a funkčnost nebyly samostatně přezkoušeny.

## Pracovní režim

- **Doma s hardwarem:** zkontrolovat díly a zapojení, zvolit správnou desku a port, nahrát sketch a zapsat skutečný výsledek testu.
- **Mimo domov bez hardwaru:** třídit sketche, psát dokumentaci a kód, případně jej kompilovat pro vybranou desku. Chování obvodu lze potvrdit až při testu doma. Práce s Arduino Cloud je možná jen podle dostupného účtu, připojení a nastavení zařízení.

## Dokumenty

- [Hardware](hardware.md) – seznam vlastněných součástek a věci k ověření.
- [Software](software.md) – IDE 2, Cloud/API, CLI a MicroPython.
- [Projekty](projekty.md) – přehled starých sketchů.
- [Arduino poznámky](arduino-poznamky.md) – technické poznatky z kódu.
- [Poznámky](poznamky.md) – další kroky a otevřené otázky.
