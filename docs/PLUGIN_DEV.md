# Plugin Development Guide

## Overview
SentryBox plugins are standalone executables that accept a **Scan Request** (JSON) via stdin and write a **Scan Result** (JSON) to stdout.

## Manifest
Every plugin must have a `manifest.json` in its directory.

```json
{
  "id": "my.plugin",
  "version": "1.0.0",
  "name": "My Plugin",
  "capabilities": ["fs_read"]
}
```

## Contract
### Input (stdin)
```json
{
  "requestId": "123",
  "target": {
    "path": "/path/to/scan",
    "type": "dir"
  },
  "config": {
    "verbose": true
  }
}
```

### Output (stdout)
```json
{
  "pluginId": "my.plugin",
  "findings": [
    {
      "id": "FIND-001",
      "severity": "high",
      "message": "Found a secret",
      "file": "config.yaml",
      "line": 10
    }
  ],
  "stats": {
    "durationMs": 100,
    "scannedFiles": 5
  }
}
```

## SDKs
SDKs for C, C++, Python, and Node.js are available in the `/sdk` directory.
