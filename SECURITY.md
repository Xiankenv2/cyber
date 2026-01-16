# Security Policy

## Reporting a Vulnerability

**SENTRYBOX** is a defensive security testing tool. If you discover a vulnerability in SENTRYBOX itself (e.g., unintended code execution from a plugin, privilege escalation, or policy bypass):

1. **Do NOT** open a public issue.
2. Email the maintainers directly.
3. We will respond within 48 hours.

## Threat Model

SENTRYBOX is designed to run **defensive** checks. However, it executes plugins which may generate load or process sensitive data.

### Trusted Use Only
- SENTRYBOX assumes the operator (user) is authorized to test the target system.
- Plugins are executed as subprocesses. By default, they inherit the user's permissions unless sandboxed (future feature).
- **Plugins must be trusted**. Do not run plugins from untrusted sources without reviewing their source code.

### Policy Enforcement
- The policy engine (when enabled) acts as a guardrail, not a sandbox. It prevents accidental misuse (e.g., rate limits) but cannot strictly prevent a malicious binary plugin from bypassing checks if it runs with user privileges.

### Data Privacy
- SENTRYBOX processes potential secrets and vulnerabilities.
- Logs and reports may contain sensitive findings.
- Use the built-in **redaction** features to mask secrets in logs/reports.
- Secure your output directories (`--output`) and log files (`--log-file`).

## Supported Versions

| Version | Supported          |
| ------- | ------------------ |
| 0.1.x   | :white_check_mark: |
