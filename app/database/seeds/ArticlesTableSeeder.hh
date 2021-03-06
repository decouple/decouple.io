<?hh // strict
use Decouple\DBAL_CLI\AwaitableSeed;
// Run the create articles table migration
class ArticlesTableSeeder extends AwaitableSeed {
  public async function run() : Awaitable<void>
  {
    $articles = $this->schema->table('articles');
    $articles->delete()->execute();
    await $articles->awaitable()->insert(Map {
      'author_id' => 1,
      'title' => 'Title',
      'content' => 'Content',
      'image' => '/img/placeholder.png'
    });
    await $articles->awaitable()->insert(Map {
      'author_id' => 1,
      'title' => 'Title 2',
      'content' => 'Content 2',
      'image' => '/img/placeholder.png'
    });
    await $articles->awaitable()->insert(Map {
      'author_id' => 1,
      'title' => 'Title 3',
      'content' => 'Content 3',
      'image' => '/img/placeholder.png'
    });
    await $articles->awaitable()->insert(Map {
      'author_id' => 1,
      'title' => 'Title 4',
      'content' => 'Content 4',
      'image' => '/img/placeholder.png'
    });
    await $articles->awaitable()->insert(Map {
      'author_id' => 1,
      'title' => 'Title 5',
      'content' => 'Content 5',
      'image' => '/img/placeholder.png'
    });
    await $articles->awaitable()->insert(Map {
      'author_id' => 1,
      'title' => 'Title 6',
      'content' => 'Content 6',
      'image' => '/img/placeholder.png'
    });
    await $articles->awaitable()->insert(Map {
      'author_id' => 1,
      'title' => 'Title 7',
      'content' => 'Content 7',
      'image' => '/img/placeholder.png'
    });
    await $articles->awaitable()->insert(Map {
      'author_id' => 1,
      'title' => 'Title 8',
      'content' => 'Content 8',
      'image' => '/img/placeholder.png'
    });
    await $articles->awaitable()->insert(Map {
      'author_id' => 1,
      'title' => 'Title 9',
      'content' => 'Content 9',
      'image' => '/img/placeholder.png'
    });
    await $articles->awaitable()->insert(Map {
      'author_id' => 1,
      'title' => 'Title 10',
      'content' => 'Content 10',
      'image' => '/img/placeholder.png'
    });
  }
}
