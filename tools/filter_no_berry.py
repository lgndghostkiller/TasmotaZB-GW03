Import("env")

def exclude_berry_sources(src_filter):
    src_filter = str(src_filter)
    excludes = [
        "xdrv_52_", "berry", "xsns_92_", "xbp_berry"
    ]
    new_lines = []
    for line in src_filter.splitlines():
        # skip berry-related files
        if any(ex in line for ex in excludes):
            continue
        new_lines.append(line)
    return "\n".join(new_lines)

env.Replace(SRC_FILTER=exclude_berry_sources(env.GetProjectOption("build_src_filter", "+<*>")))
print("🔒 Berry sources excluded by filter_no_berry.py")
