# Self-check for both reconstructions.  Run from this directory:
#   pwsh -File selfcheck.ps1
$g = Get-ChildItem "$env:LOCALAPPDATA\Microsoft\WinGet\Packages" -Recurse -Filter g++.exe |
     Select-Object -First 1 -ExpandProperty FullName
if (-not $g) { Write-Error "g++ not found"; exit 1 }

$fail = 0
foreach ($p in @("H0WS2", "H0WS3")) {
    Push-Location $p
    $out = & $g -std=gnu++17 -fsyntax-only -fdiagnostics-color=never `
                -I "D:\tmp\cppgen\$p" fixes.cpp 2>&1 | Out-String
    $rc = $LASTEXITCODE
    Pop-Location
    $errs = ([regex]::Matches($out, ': error: ')).Count
    $warns = ([regex]::Matches($out, ': warning: ')).Count
    Write-Output ("{0}: exit={1} errors={2} warnings={3}" -f $p, $rc, $errs, $warns)
    if ($rc -ne 0 -or $errs -ne 0) { $fail = 1 }
}
exit $fail
