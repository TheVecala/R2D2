import wave
import struct
import os

# --- NASTAVENÍ ---
vstupni_soubor = "r2d2.wav"  # Změň na název tvého nahraného souboru
vystupni_soubor = "data.h"
# ----------------

def convert():
    if not os.path.exists(vstupni_soubor):
        print(f"Chyba: Soubor {vstupni_soubor} nebyl nalezen! Nahraj ho do složky vlevo.")
        return

    with wave.open(vstupni_soubor, 'rb') as w:
        params = w.getparams()
        n_frames = w.getnframes()
        raw_data = w.readframes(n_frames)
        
        # Načtení dat (předpokládáme 16-bit PCM)
        samples = struct.unpack(f"<{n_frames * params.nchannels}h", raw_data)
        
        # Převod na mono, pokud je to stereo
        if params.nchannels == 2:
            samples = samples[::2]
        
        # Převod na unsigned uint16 (posun o 32768)
        unsigned_samples = [s + 32768 for s in samples]

        # Uložení do .h souboru pro Arduino
        with open(vystupni_soubor, "w") as f:
            f.write(f"// Audio data převedená z {vstupni_soubor}\n")
            f.write(f"// Sample Rate: {params.framerate} Hz\n")
            f.write(f"const uint16_t soundData[{len(unsigned_samples)}] = {{\n")
            
            for i, s in enumerate(unsigned_samples):
                f.write(f"{s},")
                if (i + 1) % 15 == 0:
                    f.write("\n")
            
            f.write("\n};")
            
        print(f"Úspěšně převedeno!")
        print(f"Počet vzorků: {len(unsigned_samples)}")
        print(f"Doporučený delayMicroseconds: {int(1000000/params.framerate)}")
        print(f"Soubor '{vystupni_soubor}' je připraven ke stažení.")

convert()