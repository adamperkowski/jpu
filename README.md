# JuleProtonUp (jpu)
A lightweight and fast tool for installing, updating and managing [Proton], [Proton-GE] and [Wine] versions.

jpu is written in [Jule], which is a low-level, compiled, memory-safe fast programming language.<br>
The tool's main goal is to provide a **faster** [ProtonUp] implementation. The original project is written in Python, which is quite slow.

## Installation

### Arch Linux
[jpu](https://aur.archlinux.org/packages/jpu) is available on the AUR. You can install it using an AUR helper, e.g. paru:
```sh
paru -S jpu
```

### Manual
You can either download the pre-built binaries from [GitHub releases](https://github.com/adamperkowski/jpu/releases) or [build from source](#building-from-source).<br>
With the binary downloaded, you can move it to a directory in your `PATH` variable, e.g. `/usr/bin`:
```sh
sudo mv jpu /usr/bin
```

## Usage
Documentation WIP...

## Building from source
To build jpu from source, you need to have the JuleC compiler (and [make]) installed. Please refer to [Jule's Manual][julec_installation].<br>
With the repository cloned and the submodules initialized with:
```sh
git submodule update --init
```
you can build the tool by running either:
```sh
make
```
or
```sh
mkdir -p build
julec . -o build/jpu
```
The `jpu` binary will be located in the `build` directory.

[Proton]: https://github.com/ValveSoftware/Proton
[Proton-GE]: https://github.com/GloriousEggroll/proton-ge-custom
[Wine]: https://www.winehq.org
[Jule]: https://jule.dev
[ProtonUp]: https://github.com/AUNaseef/protonup
[make]: https://www.gnu.org/software/make
[julec_installation]: https://manual.jule.dev/getting-started/installation/linux.html
