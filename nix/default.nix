{
  lib,
  julec,
  clangStdenv,
  curlMinimal,
  openssl,
}:

clangStdenv.mkDerivation (finalAttrs: {
  pname = "jpu";
  version = "0.0.2";

  src = ../.;

  nativeBuildInputs = [
    julec.hook
    curlMinimal
    openssl
  ];

  doCheck = false;
  JULE_OUT_NAME = "jpu";

  meta = {
    description = "Lightweight and fast tool for installing, updating and managing Proton, Proton-GE and Wine versions";
    homepage = "https://github.com/adamperkowski/jpu";
    license = lib.licenses.bsd3;
    platforms = [ "x86_64-linux" "aarch64-linux" ];
    mainProgram = "jpu";
  };
})
