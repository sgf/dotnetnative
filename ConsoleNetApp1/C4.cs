using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleNetApp1 {




    class Button {
        public Button(string name) {
            Name = name;
        }
        public string Name { get; set; }
        public Action Clicked;
    }


    class Grid {
        public Grid() {
            for (int i = 0; i < 20; i++) {
                var b = new Button(i.ToString());
                Buttons.Add(b);
            }
        }

        public List<Button> Buttons = new List<Button>();




    }
}
