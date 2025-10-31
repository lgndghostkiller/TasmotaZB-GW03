Import("env")

from SCons.Script import DefaultEnvironment
import os

# Entfernt alle Berry-bezogenen Quellen, ohne andere Tasmota-Module zu killen
def exclude_berry_sources(src):
    exts = (".ino", ".cpp", ".c")
    blocked = []
    for s in list(src):
        path = str(s)
        low = path.lower()
        if (
            ("berry" in low) or
            ("xdrv_52_" in low) or
            ("xsns_92_berry" in low) or
            ("xbp_berry" in low)
        ) and path.endswith(exts):
            blocked.append(s)
            src.remove(s)
    if blocked:
        print("🔒 Berry sources excluded by filter_no_berry.py ({} files)".format(len(blocked)))
    return src

env.AddBuildMiddleware(exclude_berry_sources, "*")
