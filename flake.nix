{
  description = "Dev environment for Go, Python and C";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
  };

  outputs = { self, nixpkgs }:
    let
      system = "x86_64-linux"; # zmień na aarch64-linux jeśli trzeba
      pkgs = import nixpkgs { inherit system; };
    in {
      devShells.${system}.default = pkgs.mkShell {
        buildInputs = [
          pkgs.go
          pkgs.python313   
          pkgs.gcc        
        ];

        shellHook = ''
          echo "Dev env ready: Go + Python + C"
          go version
          python --version
          gcc --version
        '';
      };
    };
}