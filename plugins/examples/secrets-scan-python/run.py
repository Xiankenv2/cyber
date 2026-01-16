#!/usr/bin/env python3
import json
import sys


def main() -> int:
    """Example plugin stub: read a JSON request and emit an empty findings list."""
    request = json.load(sys.stdin)
    response = {
        "plugin_id": request.get("plugin_id", "secrets-scan-python"),
        "findings": [],
    }
    json.dump(response, sys.stdout)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
