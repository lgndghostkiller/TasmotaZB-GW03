# tools/filter_no_berry.py
Import("env")

# Aktuelles SRC_FILTER übernehmen (kann str, list oder None sein)
src_filter = env.get("SRC_FILTER")

def _to_list(x):
    if x is None:
        return []
    if isinstance(x, (list, tuple)):
        return list(x)
    return str(x).split()

flt = _to_list(src_filter)

# Basis sicherstellen: alles erlauben, VCS ignorieren
if not flt:
    flt = ["+<*>", "-<.git/>", "-<.svn/>"]

# Nur Berry rausschmeißen (pfad-gezielt, ohne Kollateralschäden)
berry_rules = [
    "-<tasmota/berry/>",
    "-<tasmota/xdrv_52_*.ino>",
    "-<tasmota/xsns_92_berry*.ino>",
    "-<tasmota/xbp_berry*.ino>",
]

for r in berry_rules:
    if r not in flt:
        flt.append(r)

# Jetzt die WIRKLICHE Variable setzen
env.Replace(SRC_FILTER=" ".join(flt))
print("🔒 Berry sources excluded via extra_script (minimal, SRC_FILTER updated)")
