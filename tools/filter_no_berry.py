# tools/filter_no_berry.py
from SCons.Script import Import
Import("env")

BLOCK_SUBSTRINGS = (
    "berry",            # alle Berry-Dateien
    "xdrv_52_",         # Berry driver
    "xsns_92_berry",    # Berry sensor
    "xbp_berry",        # Berry packages
)

BLOCK_EXTS = (".ino", ".cpp", ".c")

def berry_filter(node):
    """
    Wird pro zu bauender Quelldatei aufgerufen.
    Return:
      - None  -> Datei wird ausgeschlossen
      - node  -> Datei bleibt im Build
    """
    path = str(node)
    low = path.lower()
    if path.endswith(BLOCK_EXTS) and any(s in low for s in BLOCK_SUBSTRINGS):
        print(f"🔒 Exclude Berry source: {path}")
        return None
    return node

# auf alle Quellen anwenden
env.AddBuildMiddleware(berry_filter, "*")
