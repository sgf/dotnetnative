using System;
using System.Collections.Generic;
using System.Dynamic;
using System.Linq;

namespace ClassLibrary1 {
    public class DYTest {

        public List<dynamic> GetRlt() {
            return new[] { new { id = "id", text = "text" } }.Select(x => new { Id = x.id, Text = x.text }).ToList<dynamic>();
        }
    }

}
