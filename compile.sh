
make -s -B main 2> compiler.log
echo ""
if [ "$?" = "0" ] ; then
  read -n 1 -t 3 \
    -p "Finished. View verbose output? [y/n(3s)] " reply
else
  read -n 1 -t 3 \
    -p "Compile errors present. View verbose output? [y/n(3s)] " reply
fi
echo ""

if [ "$reply" = "y" ] || [ "$reply" = "Y" ] ; then
  echo "Showing the log."
  vim -R -c 'set syntax=c' -c '/error:' compiler.log
else
  echo "Timeout reached. Defaulting \"n\"."
fi
