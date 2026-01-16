# SENTRYBOX

SENTRYBOX is a **defensive security testing** framework designed to run trusted plugins against codebases and artifacts you own or are explicitly authorized to test.
It focuses on safe, auditable workflows for security checks, not offensive exploitation.

> ⚠️ **Authorized use only**: Use SENTRYBOX only on systems, repositories, or data you own or have explicit permission to test.

## Goals (MVP)

- Lightweight CLI (`sentryctl`) to discover and run plugins.
- Clear JSON contracts for requests and findings.
- Human-readable and machine-readable output.

## Quick start

```bash
mkdir -p build
cmake -S . -B build
cmake --build build
./build/sentryctl --help
```

## CLI (initial)

```
usage: sentryctl <command> [options]

commands:
  help                    Show this help message
  version                 Print version information
  plugin list             List available plugins
  plugin info <plugin_id> Show plugin details

notes:
  This CLI is a safe scaffold for defensive testing workflows.
```

## Roadmap (high-level)

- Plugin discovery and schema validation.
- Plugin execution with timeouts and JSON I/O.
- Baselines, reporting, and opt-in automation.

## License

Apache-2.0 (recommended). Add a license file when you are ready to publish.
