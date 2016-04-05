#include <Rcpp.h>

#include "jsmn.h"

using namespace Rcpp;

jsmn_parser parser;

//' Get keys from a JSON input
//'
//' More info to hack at \url{http://zserge.com/jsmn.html}
//'
//' @param js length 1 character vector (the JSON string)
//' @export
//' @examples
//' get_keys('{ "dave" : "me", "henry" : 4, "steve" : [ "a", "b", "c" ]}')
//[[Rcpp::export]]
CharacterVector get_keys(std::string js) {

  jsmntok_t tokens[10000]; // there's a better way; quick hack

  jsmn_init(&parser);

  char *jss = (char *)js.c_str();

  int ret = jsmn_parse(&parser, jss, strlen(js.c_str()), tokens, 128);

  if (ret<0) {
    Rcout << "Bad JSON" << std::endl;
    return(NA_STRING);
  }

  if (ret<1 || tokens[0].type != JSMN_OBJECT) {
    Rcout << "Object expected" << std::endl;
    return(NA_STRING);
  }

  char val[1000];

  std::vector < std::string > out;

  for (unsigned int i=1; i<ret; i++) {
    if ((tokens[i].type == JSMN_STRING) &&
        (tokens[i].size == 1)) {
      memset(val, '\0', 128);
      strncpy(val,
              (char *)(jss + tokens[i].start),
              (tokens[i].end - tokens[i].start));
      out.push_back(std::string(val));
    }
  }

  return(wrap(out));

}
