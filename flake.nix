{
  inputs.nixpkgs.url = "nixpkgs/release-22.05";

  outputs = { nixpkgs, ... }:
    let pkgs = nixpkgs.legacyPackages.x86_64-linux;
    in {
      devShells.x86_64-linux.default = pkgs.mkShell {
        packages = (import ./replit.nix { inherit pkgs; }).deps;
      };
    };
}
