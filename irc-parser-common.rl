%%{
    machine irc_parser_common;

    crlf = "\r\n";
    separator = " ";
    valid = any -- ("\z" | "\r" | "\n");
    param_valid = valid -- separator -- ":";

    prefix = ":" param_valid+ >mark %write_prefix separator;
    command = (digit{3} | alpha+) >mark %write_command;
    trailing = separator ":" valid** >mark %write_trailing;
    middle = separator param_valid+ >mark %write_middle;
    main := prefix? command middle* trailing? %write_message;
}%%
