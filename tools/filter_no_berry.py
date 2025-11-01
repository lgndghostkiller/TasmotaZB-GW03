Import("env")

def _to_list(x):
    if x is None:
        return []
    if isinstance(x, (list, tuple)):
        return list(x)
    return [str(x)]

# Aktuellen Filter holen (kann str, list oder None sein)
current = env.get("BUILD_SRC_FILTER")
flt_list = []

if isinstance(current, str):
    # splitte grob an Whitespaces
    flt_list = current.split()
elif isinstance(current, (list, tuple)):
    flt_list = list(current)
else:
    # Standardbasis: alles erlauben, VCS ausnehmen
    flt_list = ["+<*>", "-<.git/>", "-<.svn/>"]

# Berry-Regeln hinzufügen (ohne Duplikate)
berry_rules = [
    "-<**/xdrv_52_*.ino>",
    "-<**/*berry*.ino>",
    "-<**/xsns_92_berry*.ino>",
    "-<**/xbp_berry*.ino>",
]

for r in berry_rules:
    if r not in flt_list:
        flt_list.append(r)

# Zurückschreiben als String (kompatibel für alle PIO-Versionen)
env.Replace(BUILD_SRC_FILTER=" ".join(flt_list))
print("🔒 Berry sources excluded via extra_script (BUILD_SRC_FILTER updated)")
