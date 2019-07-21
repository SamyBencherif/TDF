" Vim syntax file
" Language:     Test Descriptor Format
" Maintainer:   Samy Bencherif
" URL:          https://github.com/SamyBencherif/TDF

" set keywords

syntax keyword tdfKeywords NOOP SET WAIT ENSURE PROMPT LOGMSG LOGSENSOR TERMINATE

syntax region tdfComment start=/#/ end=/$/
syntax region tdfComment start=/###/ end=/###/

syntax region tdfMessage start=/"/ end=/"/
"syntax match tdfComment "ON"

syntax keyword tdfValue NULL_SIG ON OFF SUCCESS FAIL CHECKLOG OPEN CLOSED
syntax keyword tdfValue NO_DEVICE FILESYSTEM TESTLED


" integer
syntax match tdfValue "\<\d\+\>"

" hex
syntax match tdfValue "\<0[xX][[:xdigit:].]\+\%([pP][-+]\=\d\+\)\=\>"

" float
syntax match tdfValue "\<\d\+\.\d*\%([eE][-+]\=\d\+\)\=\>"

" supported units go here

syntax match tdfValue "\<\d\+ psi\>"
syntax match tdfValue "\<\d\+ pounds per square inch\>"
syntax match tdfValue "\<\d\+\.\d*\%([eE][-+]\=\d\+\)\= psi\>"
syntax match tdfValue "\<\d\+\.\d*\%([eE][-+]\=\d\+\)\= pounds per square inch\>"

syntax match tdfValue "\<\d\+ ms\>"
syntax match tdfValue "\<\d\+ miliseconds\>"
syntax match tdfValue "\<\d\+\.\d*\%([eE][-+]\=\d\+\)\= ms\>"
syntax match tdfValue "\<\d\+\.\d*\%([eE][-+]\=\d\+\)\= miliseconds\>"

" set highlights

"  highlight default link swiftTodos Todo
"  highlight default link swiftShebang Comment
"  highlight default link swiftMarker Comment
"
"  highlight default link swiftInterpolatedWrapper Delimiter
"  highlight default link swiftNumber Number
"  highlight default link swiftBoolean Boolean
"
"  highlight default link swiftOperator Operator
"  highlight default link swiftKeywords Keyword
"  highlight default link swiftAttributes PreProc
"  highlight default link swiftStructure Structure
"  highlight default link swiftType Type
"  highlight default link swiftImports Include
"  highlight default link swiftPreprocessor PreProc

highlight default link tdfComment Comment
highlight default link tdfKeywords Keyword
highlight default link tdfValue Number
highlight default link tdfMessage String
