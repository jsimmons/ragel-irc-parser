%%{
    machine irc_parser_common;

    crlf = "\r\n";
    separator = " ";
    valid = any -- ("\z" | "\r" | "\n");
    param_valid = valid -- separator -- ":";

    name = param_valid+ >mark %write_name;
    user = "!" param_valid+ >mark %write_user;
    host = "@" param_valid+ >mark %write_host;
    prefix = ":" name user? host? separator;
    command = (digit{3} | alpha+) >mark %write_command;
    trailing = separator ":" valid** >mark %write_trailing;
    middle = separator param_valid+ >mark %write_middle;
    main := prefix? command middle* trailing? %write_message;
}%%
