#!/usr/bin/env bash

OS=$(uname -s)
if [ ! "$OS" = Linux -a ! "$OS" = Darwin ] ; then
  echo "##### WARNING: Unsupported \"$OS\" OS. You may need to create"
  echo "#####          your own bB binaries."
fi

if [ "$(uname -s)" = Darwin ] ; then

  PROFILE=~/.zprofile
  #[ -r ~/.zshrc ] && PROFILE=~/.zshrc

else

  if [ "$(uname -s)" = Linux ] ; then
    PROFILE=~/.bashrc
  else
    PROFILE=~/.profile
  fi

  # Need to test for these, because if they exist than bash won't read .profile
  for PRO in ~/.bash_profile ~/.bash_login ~/.bashrc ; do
    [ -r "$PRO" ] && PROFILE="$PRO"
  done

fi

bB="$( cd "$(dirname "${BASH_SOURCE[0]}")" ; pwd -P )"

cat <<EOF

__________________________The_bB_Unix_Installer_v1__________________________

This script will update your $PROFILE file to
set the following variables each time you open a terminal window.

  export bB="$bB"
  export PATH="\$bB:\$PATH"

You may run this script as many times as you like, and should do so if you're
installing a new version of bB, or if you relocate this bB directory.

Hit [ENTER] to begin, or type Q and [ENTER] to quit.

EOF
read ANSWER
[ "$ANSWER" ]  && exit 1

# Ensure the profile exists
[ -r "$PROFILE" ] || touch "$PROFILE"

# Create a backup of the profile...
cp "$PROFILE" "$PROFILE.$(date +%y%m%d%H%M%S)"

# Remove any old bB entries
grep -v bB "$PROFILE" > "$PROFILE.new"

echo "##### bB variables, added by installer on $(date +%y/%m/%d)" >> "$PROFILE.new"
echo "export bB=\"$bB\"" >> "$PROFILE.new"
echo 'export PATH="$bB:$PATH"' >> "$PROFILE.new"

if [ ! -r "$PROFILE.new" ] ; then
  echo
  echo "Could not create the new profile. Is the filesystem full?"
  echo "Exiting..."
  exit 2
fi

# Move the contents instead, to preserve any custom permissions on the profile
cat "$PROFILE.new" > "$PROFILE" && rm "$PROFILE.new"

cat <<EOF
$PROFILE has been updated successfully.

To test the new setup...

  1. open another terminal window.
     (the bB and PATH variables will now be active in any new terminal window)
  2. type:  cd "\$bB/samples"
  3. type:  2600basic.sh zombie_chase.bas

This should create a zombie_chase.bas.bin binary file in the samples directory
that will work on real hardware, in stella, or any other emulator.

EOF
