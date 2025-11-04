{
  pkgs ? import <nixpkgs> { },
}:

let
  mainPkg = pkgs.callPackage ./default.nix { };
  pkgInputs = with pkgs; [ julefmt ] ++ mainPkg.nativeBuildInputs;
in
pkgs.mkShell {
  packages = pkgInputs;

  shellHook = ''
    echo -ne "------------------------------------\n "

    echo -n "${toString (map (pkg: "• ${pkg.name}\n") pkgInputs)}"

    echo "------------------------------------"
  '';
}
