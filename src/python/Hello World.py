              CALL                     1
              LOAD_FAST                0 (n)
              COMPARE_OP              88 (bool(==))
              POP_JUMP_IF_FALSE        5 (to L1)

              LOAD_FAST                0 (n)
              LOAD_CONST               2 (3)
              BINARY_OP                8 (**)
              RETURN_VALUE

      L1:     RETURN_CONST             0 (None)
      L2:     RETURN_CONST             0 (None)
