<?php
/**
 * @file
 * This template handles the layout of cj_balloon style.
 */
?>

<?php if (isset($settings['quick_links']) && !empty($settings['links'])): ?>
<!--  --><?php //foreach ($settings['links'] as $v): ?>
<!--    <div class="pane-button">-->
<!--      <a href="/--><?php //print $settings['link_page']; ?><!--" class="btn btn---><?php //print $settings['color']; ?><!--">--><?php //print $v['title']; ?><!--</a>-->
<!--    </div>-->
<!--  --><?php //endforeach; ?>
  <div class="pane-button" style="text-align: <?php print $settings['placement']; ?>">
    <?php print render($content); ?>
  </div>
<?php elseif (isset($settings['link_page']) && !isset($settings['link'])): ?>
  <div class="image-button-parent">
    <?php print render($content); ?>
    <div class="btn btn-<?php print $settings['size']; ?> btn-<?php print $settings['color']; ?>"><a href="/<?php print $settings['link_page']; ?>"><?php print $settings['title']; ?></a></div>
    <a href="/<?php print $settings['link_page']; ?>" class="btn btn-<?php print $settings['color']; ?>"><?php print $settings['title']; ?></a>
  </div>
<? else: ?>
  <div class="image-button-parent">
    <?php print render($content); ?>
    <div class="btn btn-<?php print $settings['size']; ?> btn-<?php print $settings['color']; ?>"><?php print $settings['title']; ?></div>
  </div>
<?php endif; ?>
