# SENTRYBOX – TODO

Dit document beschrijft de roadmap en concrete taken voor de ontwikkeling van **SENTRYBOX**  
(Core in C, uitbreidbaar via plugins in meerdere talen).

---

## v0.1 – MVP (Plugin runner & basis CLI)

### Repository & basis
- [ ] Git repository aanmaken (`sentrybox`)
- [ ] Basis mappenstructuur toevoegen
- [ ] `.gitignore` toevoegen (C build, Python, Node, IDE)
- [ ] `README.md` met korte uitleg + voorbeeld
- [ ] `LICENSE` (Apache-2.0 aanbevolen)
- [ ] `SECURITY.md`
- [ ] `CONTRIBUTING.md`

---

### Schema’s (contract = stabiliteit)
- [ ] `schemas/plugin.schema.json`
- [ ] `schemas/request.schema.json`
- [ ] `schemas/finding.schema.json`
- [ ] Severity levels vastleggen:
  - `info`
  - `low`
  - `medium`
  - `high`
  - `critical`

---

### sentryctl (Core CLI – C)
- [ ] Project setup (CMake)
- [ ] `sentryctl --help`
- [ ] Plugin discovery (`plugins/**/plugin.json`)
- [ ] `sentryctl plugin list`
- [ ] `sentryctl plugin info <plugin_id>`
- [ ] Capability resolver (welke plugin hoort bij welke task)

---

### Exec plugin runner
- [ ] Plugin process starten (`entry`)
- [ ] JSON request schrijven naar stdin
- [ ] JSON response lezen van stdout
- [ ] Timeout ondersteuning (bv. 30s)
- [ ] Exitcode + error handling
- [ ] Output:
  - [ ] Human readable
  - [ ] `--json` flag

---

### Voorbeeld plugins (community-proof)
- [ ] `plugins/examples/secrets-scan-python`
  - [ ] `plugin.json`
  - [ ] `run.py`
  - [ ] Simpele regex secret detectie
- [ ] `plugins/examples/c-unsafe-scan`
  - [ ] `plugin.json`
  - [ ] Detecteer `strcpy`, `gets`, `sprintf`

---

### Tests (minimaal)
- [ ] `tools/dev/run_tests.sh`
- [ ] Testdata map
- [ ] Golden JSON output test
- [ ] Plugin runner test

---

## v0.2 – Config & baselines

- [ ] `.sentrybox.json` config bestand
- [ ] Enabled/disabled plugins per project
- [ ] Exclude paths
- [ ] `sentryctl baseline save --profile <name>`
- [ ] `sentryctl baseline diff --profile <name>`
- [ ] Finding deduplication (hash-based)

---

## v0.3 – Database & reporting

- [ ] SQLite database integratie
- [ ] Tabellen:
  - [ ] runs
  - [ ] findings
  - [ ] plugins
- [ ] `sentryctl report export --json`
- [ ] `sentryctl report export --html`
- [ ] Severity summary + stats

---

## v0.4 – Daemon & scheduling

- [ ] `sentryboxd` daemon (C)
- [ ] IPC tussen `sentryctl` en daemon
- [ ] `start / stop / status`
- [ ] Scheduled scans (cron-like)
- [ ] Watch-mode (file changes)

---

## v0.5 – Plugin ecosysteem

- [ ] Plugin SDK documentatie
- [ ] `sentryctl plugin init`
  - [ ] Python
  - [ ] Node.js
  - [ ] C / C++
- [ ] Plugin packaging (`pack` / `install`)
- [ ] API version checks
- [ ] Community plugin guidelines

---

## v1.0 – Security hardening & advanced features

- [ ] Native plugin sandbox policy
- [ ] Signed plugins (trusted)
- [ ] Fuzzing framework
- [ ] Hardening profiles
- [ ] SBOM generator
- [ ] CI/CD templates (GitHub Actions)

---

## Ideeën voor later
- [ ] Web UI dashboard
- [ ] REST API
- [ ] Cloud runners
- [ ] Vulnerability feed import
- [ ] Auto-remediation (opt-in)

---

🛡️ **Core principe:**  
> *Core blijft klein en stabiel — alles is een plugin.*


