# Triangles

## Install & Run

        $ git clone https://github.com/XelerT/triangles.git & cd triangles

        $ mkdir build & cd build
        $ cmake ..
        $ make

If you want to compile unittest use -DGTESTS:BOOL=True cmake flag.

## Tests

Use python script to E2E testing:

        $ ../tests/e2e/test.py

Or build unittest binary and start it:

        $ cmake .. -DGTESTS:BOOL=True
        $ ./unitests
