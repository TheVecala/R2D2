import wave
import numpy as np

# Sem napiš název tvého souboru (musíš ho nahrát do Colabu - vlevo ikona složky)
filename = 'zvuk.wav'

def convert_to_arduino(file_path):
    with wave.open(file_path, 'rb') as wav_file:
        # Kontrola parametrů
        if wav_file.getnchannels() > 1:
            print("Chyba: Soubor musí být MONO!")
            return

        # Načtení dat
        sample_rate = wav_file.getframerate()
        frames = wav_file.readframes(wav_file.getnframes())
        data = np.frombuffer(frames, dtype=np.uint8) # Pro 8-bit PCM

        # Převod na 12-bit rozsah pro DAC (0-4095)
        # 8-bit (0-255) vynásobíme 16x
        data_12bit = data.astype(np.uint16) * 16

        # Generování textu pro Arduino
        output = f"// Sample Rate: {sample_rate} Hz\n"
        output += f"const uint16_t soundData[{len(data_12bit)}] PROGMEM = {{\n  "

        for i, val in enumerate(data_12bit):
            output += str(val) + ", "
            if (i + 1) % 12 == 0: # Každých 12 čísel nový řádek pro přehlednost
                output += "\n  "

        output += "\n};"

        with open('arduino_data.txt', 'w') as f:
            f.write(output)
        print("Hotovo! Soubor 'arduino_data.txt' byl vytvořen.")

convert_to_arduino(filename)